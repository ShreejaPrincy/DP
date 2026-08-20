//REcursion
// TC: O(2^n)
// SC: O(n)
class Solution {
public:
    int n;
    int solve(int i,int buy,vector<int>&prices){
        if(i>=n)    return 0;

        if(buy){
            return max(-prices[i]+solve(i+1,0,prices),solve(i+1,1,prices));
        }
        return max(prices[i]+solve(i+2,1,prices),solve(i+1,0,prices));
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        return solve(0,1,prices);
    }
};



//Memoisation
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int n;
    int solve(vector<vector<int>>&dp,int i,int buy,vector<int>&prices){
        if(i>=n)    return 0;

        if(dp[i][buy]!=-1)  return dp[i][buy];
        
        if(buy){
            return dp[i][buy]=max(-prices[i]+solve(dp,i+1,0,prices),solve(dp,i+1,1,prices));
        }
        return dp[i][buy]=max(prices[i]+solve(dp,i+2,1,prices),solve(dp,i+1,0,prices));
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        return solve(dp,0,1,prices);
    }
};



//Tabulation
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};




//Space Optimisation
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        //vector<vector<int>>dp(n+2,vector<int>(2,0));
        vector<int>front1(2,0),front2(2,0),curr(2,0);

        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+front1[0],front1[1]);
            curr[0]=max(prices[i]+front2[1],front1[0]);

            front2=front1;
            front1=curr;
        }
        return front1[1];
    }
};
