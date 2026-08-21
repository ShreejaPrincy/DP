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
