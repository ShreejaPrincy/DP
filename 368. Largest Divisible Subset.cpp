// 1D DP + Reconstruction
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>dp(n,1),hash(n);

        int idx=0,ans=1;
        
        for(int i=0;i<n;i++){
            hash[i]=i;

            for(int prev=0;prev<i;prev++){

                if(nums[i]%nums[prev]==0 && 
                   1+dp[prev]>dp[i]){

                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }

            if(ans<dp[i]){
                ans=dp[i];
                idx=i;
            }
        }

        vector<int>temp;

        temp.push_back(nums[idx]);

        while(idx!=hash[idx]){
            idx=hash[idx];
            temp.push_back(nums[idx]);
        }

        return temp;
    }
};
