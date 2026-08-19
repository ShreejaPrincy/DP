// Recursion
// TC: O(2^(n+m)) in the worst case
// SC: O(n+m) -> recursion stack
//     (excluding input strings)

class Solution {
public:
    bool solve(int i, int j, string s, string t) {
        if (i < 0 && j < 0) return true;

        if (i >= 0 && j < 0) return false;

        if (i < 0 && j >= 0) {
            for (int jj = 0; jj <= j; jj++) {
                if (t[jj] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == t[j] || t[j] == '?')
            return solve(i - 1, j - 1, s, t);

        if (t[j] == '*') {
            // '*' matches:
            // 1. ZERO characters -> j-1
            // 2. ONE or MORE characters -> i-1
            return solve(i, j - 1, s, t) ||
                   solve(i - 1, j, s, t);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return solve(n - 1, m - 1, s, p);
    }
};




// Memoisation
// TC: O(n * m)
// SC: O(n * m) -> DP array
//     + O(n + m) -> recursion stack
// Overall SC: O(n * m)

class Solution {
public:
    bool solve(vector<vector<int>>& dp, int i, int j,
               string s, string t) {

        if (i < 0 && j < 0) return true;

        if (i >= 0 && j < 0) return false;

        if (i < 0 && j >= 0) {
            for (int jj = 0; jj <= j; jj++) {
                if (t[jj] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j] || t[j] == '?')
            return dp[i][j] = solve(dp, i - 1, j - 1, s, t);

        if (t[j] == '*') {
            // '*' matches:
            // 1. ZERO characters -> j-1
            // 2. ONE or MORE characters -> i-1
            return dp[i][j] = solve(dp, i, j - 1, s, t) ||
                              solve(dp, i - 1, j, s, t);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(dp, n - 1, m - 1, s, p);
    }
};




// Tabulation
// TC: O(n * m)
// SC: O(n * m)

class Solution {
public:
    bool isMatch(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Non-empty string cannot match empty pattern
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // Empty string can match pattern only if
        // all characters in pattern are '*'
        for (int j = 1; j <= m; j++) {
            bool flag = true;

            for (int jj = 1; jj <= j; jj++) {
                if (t[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Same character OR '?'
                if (s[i - 1] == t[j - 1] || t[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*':
                // 1. ZERO characters -> dp[i][j-1]
                // 2. ONE/MORE characters -> dp[i-1][j]
                else if (t[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] ||
                                dp[i - 1][j];
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
