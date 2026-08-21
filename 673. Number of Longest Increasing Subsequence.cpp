// Number of LIS
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,1),count(n,1);
        int ans=1;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    count[i]=count[prev];
                }
                else if(nums[prev]<nums[i] && dp[i]==1+dp[prev]){
                    count[i]+=count[prev];
                }
            }
            ans=max(ans,dp[i]);
        }
        int num=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans)  num+=count[i];
        }
        return num;
    }
};
