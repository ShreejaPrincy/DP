// TC: O(n*m)
// SC: O(n*m)

class Solution {
public:

    int lcs(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // NOTE: Index Shifting
                // dp[i][j] corresponds to s1[i-1] and s2[j-1]

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        int common = lcs(word1, word2);

        return n + m - 2 * common;
    }
};
