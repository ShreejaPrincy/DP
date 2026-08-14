// TC: O(n*m)
// SC: O(n*m) + O(n) -> DP table + answer string

class Solution {
public:
    string findLCS(int n, int m, string &s1, string &s2) {

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Tabulation
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Backtracking to find the LCS
        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0) {

            // Characters match
            if(s1[i-1] == s2[j-1]) {
                ans += s1[i-1];

                i--;
                j--;
            }

            // Move towards the larger value
            else if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }

            else {
                j--;
            }
        }

        // We constructed the answer backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
