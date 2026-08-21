//Recursion
// TC: O(2^n)
// SC: O(n)
class Solution {
public:
    int n;
    int solve(int i,int prev,vector<int>&nums){
        if(i==n)    return 0;

        int take=0;
        if(prev==-1 || nums[prev]<nums[i])      take=1+solve(i+1,i,nums);

        int skip=solve(i+1,prev,nums);

        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        return solve(0,-1,nums);
    }
};




//Memoisation
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int n;
    int solve(vector<vector<int>>&dp,int i,int prev,vector<int>&nums){
        if(i==n)    return 0;

        if(dp[i][prev+1]!=-1)   return dp[i][prev+1];

        int take=0;
        if(prev==-1 || nums[prev]<nums[i])      take=1+solve(dp,i+1,i,nums);

        int skip=solve(dp,i+1,prev,nums);

        return dp[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(dp,0,-1,nums);
    }
};




// Tabulation
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int n;

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<n;prev++){

                int take=0;

                if(prev==-1 || nums[prev]<nums[i])
                    take=1+dp[i+1][i+1];

                int skip=dp[i+1][prev+1];

                dp[i][prev+1]=max(take,skip);
            }
        }

        return dp[0][0];
    }
};




// Space Optimisation
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int n;

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        vector<int>front(n+1,0),curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<n;prev++){

                int take=0;

                if(prev==-1 || nums[prev]<nums[i])
                    take=1+front[i+1];

                int skip=front[prev+1];

                curr[prev+1]=max(take,skip);
            }

            front=curr;
        }

        return front[0];
    }
};




// 1D DP(another method)
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int n;

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        vector<int>dp(n+1,1);

        int ans=1;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){

                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};
