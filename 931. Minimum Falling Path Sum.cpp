// Recursion
// Time Complexity: O(3^n)
// Space Complexity: O(n)  -> recursion stack

class Solution {
public:
    int solve(int n, int i, int j, vector<vector<int>>& matrix) {

        // Invalid column
        if(j < 0 || j >= n)
            return 1e9;

        // Base case: last row
        if(i == n - 1)
            return matrix[i][j];

        int down = solve(n, i + 1, j, matrix);
        int left = solve(n, i + 1, j - 1, matrix);
        int right = solve(n, i + 1, j + 1, matrix);

        return matrix[i][j] +
               min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int ans = 1e9;

        // Path can start from any column
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(n, 0, j, matrix));
        }

        return ans;
    }
};




// Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n)
// Overall Space Complexity: O(n^2)

class Solution {
public:
    int solve(vector<vector<int>>& dp, int n, int i, int j,
              vector<vector<int>>& matrix) {

        // Invalid column
        if(j < 0 || j >= n)
            return 1e9;

        // Base case: last row
        if(i == n - 1)
            return matrix[i][j];

        // Already calculated
        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = solve(dp, n, i + 1, j, matrix);
        int left = solve(dp, n, i + 1, j - 1, matrix);
        int right = solve(dp, n, i + 1, j + 1, matrix);

        return dp[i][j] =
            matrix[i][j] + min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        // Path can start from any column
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(dp, n, 0, j, matrix));
        }

        return ans;
    }
};



// Tabulation
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: first row
        dp[0] = matrix[0];

        // Fill from top to bottom
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < n; j++) {

                int left = 1e9;
                int middle = 1e9;
                int right = 1e9;

                if(j - 1 >= 0)
                    left = matrix[i][j] + dp[i - 1][j - 1];

                middle = matrix[i][j] + dp[i - 1][j];

                if(j + 1 < n)
                    right = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({left, middle, right});
            }
        }

        // Path can end at any column
        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};



