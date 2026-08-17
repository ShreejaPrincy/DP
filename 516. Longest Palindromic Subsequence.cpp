// TC: O(n*n)
// SC: O(n*n)

class Solution {
public:

    int lcs(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // NOTE: Index Shifting
                // dp[i][j] corresponds to s1[i-1] and s2[j-1].
                // Extra 0th row/column represent an empty string.

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {

        string s2 = s;

        reverse(s2.begin(), s2.end());

        return lcs(s, s2);
    }
};
