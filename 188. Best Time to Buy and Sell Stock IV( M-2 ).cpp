//Recursion
// TC: O(2^n)
// SC: O(n)
class Solution {
public:
    int n;
    int solve(int i,int trans,int k,vector<int> & prices){
        if(trans==2*k || i==n)  return 0;

        if(trans%2==0){ //buy
            return max(
                -prices[i]+solve(i+1,trans+1,k,prices),
                solve(i+1,trans,k,prices)
                );
        }
        return max(
                prices[i]+solve(i+1,trans+1,k,prices),
                solve(i+1,trans,k,prices)
                );
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        return solve(0,0,k,prices);
    }
};




//MEmoisation
// TC: O(n*k)
// SC: O(n*k)
class Solution {
public:
    int n;
    int solve(vector<vector<int>>&dp,int i,int trans,int k,vector<int> & prices){
        if(trans==2*k || i==n)  return 0;

        if(dp[i][trans]!=-1)    return dp[i][trans];

        if(trans%2==0){ //buy
            return dp[i][trans]= max(
                -prices[i]+solve(dp,i+1,trans+1,k,prices),
                solve(dp,i+1,trans,k,prices)
                );
        }
        return dp[i][trans]= max(
                prices[i]+solve(dp,i+1,trans+1,k,prices),
                solve(dp,i+1,trans,k,prices)
                );
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        return solve(dp,0,0,k,prices);
    }
};




//TAbulation
// TC: O(n*k)
// SC: O(n*k)
class Solution {
public:
    int n;
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){ //buy
                    dp[i][trans]= max(
                        -prices[i]+dp[i+1][trans+1],
                        dp[i+1][trans]
                        );
                }
                else{
                    dp[i][trans]= max(
                        prices[i]+dp[i+1][trans+1],
                        dp[i+1][trans]
                        );
                }
            }
        }
        return dp[0][0];
    }
};



//Space optimisation
// TC: O(n*k)
// SC: O(k)
class Solution {
public:
    int n;
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        //vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        vector<int>prev(2*k+1,0),curr(2*k+1,0);

        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){ //buy
                    curr[trans]= max(
                        -prices[i]+prev[trans+1],
                        prev[trans]
                        );
                }
                else{
                    curr[trans]= max(
                        prices[i]+prev[trans+1],
                        prev[trans]
                        );
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};
