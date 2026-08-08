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



