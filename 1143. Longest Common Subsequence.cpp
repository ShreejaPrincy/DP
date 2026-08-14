// Recursion
// TC: O(2^(n+m))
// SC: O(n+m)  -> Recursion stack

class Solution {
public:
    int solve(int i, int j, string s1, string s2) {
        if(i < 0 || j < 0)
            return 0;

        if(s1[i] == s2[j])
            return 1 + solve(i-1, j-1, s1, s2);

        return max(
            solve(i, j-1, s1, s2),
            solve(i-1, j, s1, s2)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return solve(n-1, m-1, text1, text2);
    }
};




// Memoisation
// TC: O(n*m)
// SC: O(n*m) + O(n+m) -> DP array + Recursion stack

class Solution {
public:
    int solve(vector<vector<int>>& dp, int i, int j,
              string s1, string s2) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(dp, i-1, j-1, s1, s2);

        return dp[i][j] = max(
            solve(dp, i, j-1, s1, s2),
            solve(dp, i-1, j, s1, s2)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(dp, n-1, m-1, text1, text2);
    }
};



// NOTE: Index Shifting
// In recursion, we use i = n-1 and j = m-1, so when i/j becomes -1,
// we need a base case for the negative index.
// In tabulation, to avoid negative indices, we shift indices by +1.
// Therefore: s1[i-1], s2[j-1] and dp[n+1][m+1].
// first do index shifting in recursion code only , it will be easier to code for the tabulation, space optimisation


//Tabulation
// TC: O(n*m)
// SC: O(n*m)

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};




//Space optimisation
// TC: O(n*m)
// SC: O(m) -> Only previous and current row

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];

                else
                    curr[j] = max(curr[j-1], prev[j]);
            }

            prev = curr;
        }

        return prev[m];
    }
};
