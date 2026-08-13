// Recursion
// Time Complexity: O(2^N)
// Space Complexity: O(N) -> Recursion Stack

class Solution {
  public:
    int solve(int i,int n,vector<int>&price){
        if(n==0)    return 0;
        if(i==0){
            return n*price[0];
        }
        
        int take=0;
        if(n-(i+1)>=0)
            take=price[i]+solve(i,n-(i+1),price);
        
        int skip=solve(i-1,n,price);
        
        return max(take,skip);
    }
    
    int cutRod(vector<int> &price) {
        int n=price.size();
        return solve(n-1,n,price);
    }
};



// Memoisation
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) + O(N)
//                  DP Array + Recursion Stack

class Solution {
  public:
    int solve(vector<vector<int>>&dp,int i,int n,vector<int>&price){
        if(n==0)    return 0;
        if(i==0){
            return n*price[0];
        }
        
        if(dp[i][n]!=-1)
            return dp[i][n];
        
        int take=0;
        if(n-(i+1)>=0)
            take=price[i]+solve(dp,i,n-(i+1),price);
        
        int skip=solve(dp,i-1,n,price);
        
        return dp[i][n]=max(take,skip);
    }
    
    int cutRod(vector<int> &price) {
        int n=price.size();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return solve(dp,n-1,n,price);
    }
};



// Tabulation
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        
        for(int w=1;w<=n;w++){
            dp[0][w]=w*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=n;w++){
                
                int take=0;
                if(w-(i+1)>=0)
                    take=price[i]+dp[i][w-(i+1)];
                
                int skip=dp[i-1][w];
                
                dp[i][w]=max(take,skip);
            }
        }
        
        return dp[n-1][n];
    }
};



// Space Optimisation - 2D -> 1D
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        
        //vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        vector<int>prev(n+1,0);
        
        prev[0]=0;
       
        for(int w=1;w<=n;w++){
            prev[w]=w*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=n;w++){
                
                int take=0;
                if(w-(i+1)>=0)
                    take=price[i]+prev[w-(i+1)];
                
                int skip=prev[w];
                
                prev[w]=max(take,skip);
            }
        }
        
        return prev[n];
    }
};
