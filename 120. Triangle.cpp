// Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle) {

        // Base Case
        if (i == triangle.size() - 1)
            return triangle[i][j];

        int down = solve(i + 1, j, triangle);
        int diagonal = solve(i + 1, j + 1, triangle);

        return triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        return solve(0, 0, triangle);
    }
};




// Note:
// Do not use -1 as the unvisited marker because the triangle
// can contain negative values, and a valid DP answer can be -1.
// Use INT_MAX as the unvisited marker instead, as it cannot be
// a valid minimum path sum under the given constraints.

// Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n)
// Overall Space Complexity: O(n^2)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        // Base Case: last row
        if (i == triangle.size() - 1)
            return triangle[i][j];

        // Already calculated
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = solve(i + 1, j, triangle, dp);

        int diagonal = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] =
            triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(0, 0, triangle, dp);
    }
};



// Tabulation
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base Case: Last row
        for(int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Bottom-up
        for(int i = n - 2; i >= 0; i--) {

            for(int j = i; j >= 0; j--) {

                int below = dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] +
                           min(below, diagonal);
            }
        }

        return dp[0][0];
    }
};



// Space Optimization
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<int> dp = triangle[n - 1];

        for(int i = n - 2; i >= 0; i--) {

            for(int j = 0; j <= i; j++) {

                dp[j] = triangle[i][j] +
                        min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};
