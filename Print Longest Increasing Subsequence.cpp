// 1D DP + LIS Reconstruction
// TC: O(n^2)
// SC: O(n)

class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        
        int ans=1,idx=0;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                idx=i;
            }
        }
        vector<int>a;
        a.push_back(nums[idx]);
        while(hash[idx]!=idx){
            idx=hash[idx];
            a.push_back(nums[idx]);
        }
        reverse(a.begin(),a.end());
        return a;
    }
};
