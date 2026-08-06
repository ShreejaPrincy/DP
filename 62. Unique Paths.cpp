// Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(int i, int j, int m, int n) {

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return 1;

        // Out of bounds
        if (i >= m || j >= n)
            return 0;

        // Move Down + Move Right
        return solve(i + 1, j, m, n) +
               solve(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n) {

        return solve(0, 0, m, n);
    }
};




// Memoization (Top-Down DP)
// Time Complexity: O(m × n)
// Space Complexity: O(m × n) + O(m + n)

class Solution {
public:
    int solve(vector<vector<int>>& dp, int i, int j, int m, int n) {

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return dp[i][j] = 1;

        // Out of bounds
        if (i >= m || j >= n)
            return 0;

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move Down + Move Right
        return dp[i][j] = solve(dp, i + 1, j, m, n) +
                          solve(dp, i, j + 1, m, n);
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dp, 0, 0, m, n);
    }
};




// Tabulation (Bottom-Up DP)
// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base Case
        dp[m - 1][n - 1] = 1;

        // Fill the table from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // Skip the destination cell
                if (i == m - 1 && j == n - 1)
                    continue;

                int down = 0;
                int right = 0;

                if (i + 1 < m)
                    down = dp[i + 1][j];

                if (j + 1 < n)
                    right = dp[i][j + 1];

                dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
};



// Space Optimization
// Time Complexity: O(m × n)
// Space Complexity: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> curr(n, 0);
        vector<int> prev(n, 0);

        // Base Case
        curr[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                int down = 0;
                int right = 0;

                if (i + 1 < m)
                    down = prev[j];

                if (j + 1 < n)
                    right = curr[j + 1];

                curr[j] = down + right;
            }

            prev = curr;
        }

        return prev[0];
    }
};


