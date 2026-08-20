//Recursion
class Solution {
public:
    int n;
    int solve(int i,int buy,int cap,vector<int>& prices){
        if(i==n || cap==0)  return 0;

        if(buy){
            return max(
                -prices[i]+solve(i+1,0,cap,prices),
                solve(i+1,1,cap,prices)
            );
        }
        return max(
            prices[i]+solve(i+1,1,cap-1,prices),
            solve(i+1,0,cap,prices)
        );
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        return solve(0,1,2,prices);
    }
};




//Memoisation
class Solution {
public:
    int n;
    int solve(vector<vector<vector<int>>>&dp,int i,int buy,int cap,vector<int>& prices){
        if(i==n || cap==0)  return 0;

        if(dp[i][buy][cap]!=-1)     return dp[i][buy][cap];

        if(buy){
            return dp[i][buy][cap]=max(
                -prices[i]+solve(dp,i+1,0,cap,prices),
                solve(dp,i+1,1,cap,prices)
            );
        }
        return dp[i][buy][cap]=max(
            prices[i]+solve(dp,i+1,1,cap-1,prices),
            solve(dp,i+1,0,cap,prices)
        );
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(dp,0,1,2,prices);
    }
};



//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        /*
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0]=0;
            }
        }
        */
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap]=max(
                            -prices[i]+dp[i+1][0][cap],
                            dp[i+1][1][cap]
                        );
                    }
                    else{
                        dp[i][buy][cap]=max(
                            prices[i]+dp[i+1][1][cap-1],
                            dp[i+1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};



//Space Optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

//      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<int>>front(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        
        /*
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0]=0;
            }
        }
        */

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap]=max(
                            -prices[i]+front[0][cap],
                            front[1][cap]
                        );
                    }
                    else{
                        curr[buy][cap]=max(
                            prices[i]+front[1][cap-1],
                            front[0][cap]
                        );
                    }
                }
            }
            front=curr;
        }

        return front[1][2];
    }
};



