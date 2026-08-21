// Longest Bitonic Subsequence
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int longestBitonicSequence(int n, vector<int> &nums) {

        vector<int>dp(n+1,1);

        // Increasing part
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                }
            }
        }

        vector<int>dp2(n+1,1);
        int ans_max=0;

        // Decreasing part
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i] && dp2[i]<1+dp2[prev]){
                    dp2[i]=1+dp2[prev];
                }
            }

            // Must have both increasing and decreasing parts
            if(dp[i]>1 && dp2[i]>1){
                ans_max=max(ans_max,dp[i]+dp2[i]-1);
            }
        }

        return ans_max;
    }
};
