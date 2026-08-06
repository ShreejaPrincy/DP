// Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n) {

        if (i >= m || j >= n)
            return 0;

        if (obstacleGrid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        return solve(obstacleGrid, i + 1, j, m, n) +
               solve(obstacleGrid, i, j + 1, m, n);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(obstacleGrid, 0, 0, m, n);
    }
};


// Memoization
// Time Complexity: O(m × n)
// Space Complexity: O(m × n) + O(m+n)

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp,
              int i, int j, int m, int n) {

        if (i >= m || j >= n)
            return 0;

        if (obstacleGrid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] =
            solve(obstacleGrid, dp, i + 1, j, m, n) +
            solve(obstacleGrid, dp, i, j + 1, m, n);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(obstacleGrid, dp, 0, 0, m, n);
    }
};



// Tabulation
// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                long long down = 0;
                long long right = 0;

                if (i + 1 < m)
                    down = dp[i + 1][j];

                if (j + 1 < n)
                    right = dp[i][j + 1];

                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = down + right;
            }
        }

        return (int)dp[0][0];
    }
};



// Space Optimization
// Time Complexity: O(m × n)
// Space Complexity: O(n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<long long> curr(n, 0);
        vector<long long> prev(n, 0);

        curr[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                long long down = 0;
                long long right = 0;

                if (i + 1 < m)
                    down = prev[j];

                if (j + 1 < n)
                    right = curr[j + 1];

                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else
                    curr[j] = down + right;
            }

            prev = curr;
        }

        return (int)prev[0];
    }
};


