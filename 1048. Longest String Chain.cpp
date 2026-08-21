// TC: O(n^2 * L)
// SC: O(n)
class Solution {
public:
    int n;
    bool comparee(string s,string t){
        if(s.size()+1!=t.size())    return false;

        int i=0,j=0;
        while(j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==s.size() && j==t.size();
    }
    static bool comp(string &s , string &t){
        return s.size()<t.size();
    }
    int longestStrChain(vector<string>& nums) {
        n=nums.size();

        sort(nums.begin(),nums.end(),comp);

        vector<int>dp(n+1,1);
        int ans=1;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(comparee(nums[prev],nums[i]) && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
