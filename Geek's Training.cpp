// Recursion
// Time Complexity: O(3 × 2^(n-1)) ≈ O(2^n)
// Space Complexity: O(n)

class Solution {
  public:
    int n;
    
    int solve(int i,vector<vector<int>>&mat,int prev){
        if(i>=n)    return 0;
        
        int ans=0;
        for(int j=0;j<3;j++){
            if(prev!=j){
                int maxi=mat[i][j]+solve(i+1,mat,j);
                ans=max(maxi,ans);
            }
        }
        
        return ans;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        n=mat.size();
        
        return solve(0,mat,3);
    }
};


//memoisation
// Time Complexity: O(n * 4 * 3) = O(n)
// Space Complexity: O(n * 4) + O(n) = O(n)
// (DP table + recursion stack)

class Solution {
  public:
    int n;
    
    int solve(int i,vector<vector<int>>&mat,int prev,vector<vector<int>>&dp){
        if(i>=n)    return 0;
        
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int ans=0;
        for(int j=0;j<3;j++){
            if(prev!=j){
                int maxi=mat[i][j]+solve(i+1,mat,j,dp);
                ans=max(maxi,ans);
            }
        }
        
        return dp[i][prev]=ans;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        n=mat.size();
        
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        return solve(0, mat, 3, dp);
};


// Tabulation (Bottom-Up DP)
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
  public:
    int n;
    
    int maximumPoints(vector<vector<int>>& mat) {
        n=mat.size();
        
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        
        n=n-1;
        
        dp[n][0]=max(mat[n][1],mat[n][2]);
        dp[n][1]=max(mat[n][0],mat[n][2]);
        dp[n][2]=max(mat[n][0],mat[n][1]);
        dp[n][3]=max(dp[n][0],max(dp[n][1],dp[n][2]));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=3;j++){
                dp[i][j]=0;
                for(int prev=0;prev<3;prev++){
                    if(prev!=j){
                        dp[i][j]=max(dp[i][j],mat[i][prev]+dp[i+1][prev]);
                    }
                }
            }
        }
        
        return dp[0][3];
    }
};
