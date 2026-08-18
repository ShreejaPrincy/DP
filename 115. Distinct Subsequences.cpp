//Recursion
// TC: O(2^n)
// SC: O(n) -> Recursion stack
class Solution {
public:
    int solve(int i,int j,string &s,string &t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i]==t[j])  return solve(i-1,j-1,s,t)+solve(i-1,j,s,t);

        return solve(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        return solve(n-1,m-1,s,t);
    }
};



//Memoisation
// TC: O(n*m)
// SC: O(n*m) + O(n) -> DP table + Recursion stack
class Solution {
public:
    int solve(vector<vector<int>>&dp,int i,int j,string &s,string &t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        if(s[i]==t[j])  return dp[i][j]=solve(dp,i-1,j-1,s,t)+solve(dp,i-1,j,s,t);

        return dp[i][j]=solve(dp,i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(dp,n-1,m-1,s,t);
    }
};


//Tabulation
// TC: O(n*m)
// SC: O(n*m)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==t[j-1])  dp[i][j]=dp[i-1][j-1]+dp[i-1][j];

                else                dp[i][j]=dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};



//space optimisation in 1D
// TC: O(n*m)
// SC: O(m)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<double>prev(m+1,0);

        prev[0]=1;        

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){

                if(s[i-1]==t[j-1])  prev[j]=prev[j-1]+prev[j];

            }
        }

        return (int)prev[m];
    }
};
