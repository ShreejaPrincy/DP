// Recursion
// TC: O(2^n)
// SC: O(n)

class Solution {
public:
    int solve(int i,bool buy,vector<int>&nums){
        if(i==nums.size())    return 0;

        if(buy){
            return max(-nums[i]+solve(i+1,0,nums),solve(i+1,1,nums));
        }

        return max(nums[i]+solve(i+1,1,nums),solve(i+1,0,nums));
    }

    int maxProfit(vector<int>& prices) {
        bool buy=1;
        return solve(0,buy,prices);
    }
};



// Memoisation
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int solve(vector<vector<int>>&dp,int i,bool buy,vector<int>&nums){
        if(i==nums.size())    return 0;

        if(dp[i][buy]!=-1)    return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-nums[i]+solve(dp,i+1,0,nums),solve(dp,i+1,1,nums));
        }

        return dp[i][buy]=max(nums[i]+solve(dp,i+1,1,nums),solve(dp,i+1,0,nums));
    }

    int maxProfit(vector<int>& prices) {
        bool buy=1;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(dp,0,buy,prices);
    }
};




// Tabulation
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        bool buy=1;
        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][buy]=max(-nums[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(nums[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};



// Space Optimized Tabulation
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        bool buy=1;
        int n=nums.size();

        vector<int>curr(2,0),front(2,0);

        front[0]=front[1]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy]=max(-nums[i]+front[0],front[1]);
                }
                else{
                    curr[buy]=max(nums[i]+front[1],front[0]);
                }
            }

            front=curr;
        }

        return front[1];
    }
};



// Space Optimized Tabulation (using variable)
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        int aheadNotBuy = 0, aheadBuy = 0;
        int curBuy, curNotBuy;

        for(int ind = n-1; ind >= 0; ind--) {

            curNotBuy = max(nums[ind] + aheadBuy,
                            0 + aheadNotBuy);

            curBuy = max(-nums[ind] + aheadNotBuy,
                         0 + aheadBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return aheadBuy;
    }
};

