// Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j) {

        if (i >= m || j >= n)
            return 1e9;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        int right = solve(grid, m, n, i, j + 1);
        int down = solve(grid, m, n, i + 1, j);

        return grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        return solve(grid, m, n, 0, 0);
    }
};


// Memoization
// Time Complexity: O(m × n)
// Space Complexity: O(m × n) + O(m+n)

class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& grid,
              int m, int n, int i, int j) {

        if (i >= m || j >= n)
            return 1e9;

        if (i == m - 1 && j == n - 1)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = grid[i][j] +
                          min(solve(dp, grid, m, n, i, j + 1),
                              solve(dp, grid, m, n, i + 1, j));
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dp, grid, m, n, 0, 0);
    }
};



// Tabulation
// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Base Case
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        // Fill from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                int down = 1e9;
                int right = 1e9;

                if (i + 1 < m)
                    down = dp[i + 1][j];

                if (j + 1 < n)
                    right = dp[i][j + 1];

                dp[i][j] = grid[i][j] + min(down, right);
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
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> curr(n, 0), prev(n, 0);

        // Base Case
        curr[n - 1] = grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                int down = 1e9;
                int right = 1e9;

                if (i + 1 < m)
                    down = prev[j];

                if (j + 1 < n)
                    right = curr[j + 1];

                curr[j] = grid[i][j] + min(down, right);
            }

            prev = curr;
        }

        return prev[0];
    }
};


