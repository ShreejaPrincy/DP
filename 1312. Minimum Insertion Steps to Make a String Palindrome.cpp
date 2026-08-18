// TC: O(n*n)
// SC: O(n*n)

class Solution {
public:

    int lcs(int n, int m, string &s1, string &s2) {

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

    int minInsertions(string s) {

        string s1 = s;

        reverse(s.begin(), s.end());

        string s2 = s;

        int n = s1.size();

        // LPS = LCS(original, reverse)
        int lps = lcs(n, n, s1, s2);

        // Minimum insertions = n - LPS
        return n - lps;
    }
};
