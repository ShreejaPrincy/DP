//RECURSION
// TC: O(3^(n+m)) approximately
// SC: O(n+m) -> Recursion stack

class Solution {
public:
    int solve(int i, int j, string &s1, string &s2) {

        if(i == 0)
            return j;

        if(j == 0)
            return i;

        if(s1[i-1] == s2[j-1])
            return solve(i-1, j-1, s1, s2);

        int insert = 1 + solve(i, j-1, s1, s2);
        int del = 1 + solve(i-1, j, s1, s2);
        int replace = 1 + solve(i-1, j-1, s1, s2);

        return min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        return solve(n, m, word1, word2);
    }
};



//MEMOISATION
// TC: O(n*m)
// SC: O(n*m) + O(n+m)
// DP table + Recursion stack

class Solution {
public:
    int solve(vector<vector<int>>& dp, int i, int j,
              string &s1, string &s2) {

        if(i == 0)
            return j;

        if(j == 0)
            return i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i-1] == s2[j-1])
            return dp[i][j] =
                solve(dp, i-1, j-1, s1, s2);

        int insert = 1 + solve(dp, i, j-1, s1, s2);
        int del = 1 + solve(dp, i-1, j, s1, s2);
        int replace = 1 + solve(dp, i-1, j-1, s1, s2);

        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(dp, n, m, word1, word2);
    }
};



///Tabulation
// TC: O(n*m)
// SC: O(n*m)

class Solution {
public:
    int minDistance(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base cases
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;

        for(int j = 0; j <= m; j++)
            dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // NOTE: Index Shifting
                // dp[i][j] corresponds to s1[i-1] and s2[j-1].

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];

                else {

                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insert, del, replace});
                }
            }
        }

        return dp[n][m];
    }
};



//Space optimisation
// TC: O(n*m)
// SC: O(m)

class Solution {
public:
    int minDistance(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        // First row
        for(int j = 0; j <= m; j++)
            prev[j] = j;

        for(int i = 1; i <= n; i++) {

            // First column
            curr[0] = i;

            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1];

                else {

                    int insert = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];

                    curr[j] = min({insert, del, replace});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};




