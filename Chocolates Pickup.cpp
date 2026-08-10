// Recursion
// Time Complexity: O(9^n)
// Space Complexity: O(n)
//        → recursion stack

class Solution {
public:
    int n, m;

    int solve(int i, int j1, int j2,
              vector<vector<int>>& grid) {

        // Invalid columns
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        // Last row
        if(i == n - 1) {

            if(j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

        int temp = -1e9;

        // 3 choices for Robot 1
        // 3 choices for Robot 2
        // Total = 9 combinations

        for(int k = -1; k <= 1; k++) {

            for(int l = -1; l <= 1; l++) {

                int chocolates;

                if(j1 == j2)
                    chocolates = grid[i][j1];
                else
                    chocolates = grid[i][j1] + grid[i][j2];

                chocolates += solve(
                    i + 1,
                    j1 + k,
                    j2 + l,
                    grid
                );

                temp = max(temp, chocolates);
            }
        }

        return temp;
    }

    int maxChocolate(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        return solve(0, 0, m - 1, grid);
    }
};




// Memoization
// Time Complexity: O(n * m^2)
// Space Complexity: O(n * m^2) + O(n)
// Overall Space Complexity: O(n * m^2)

class Solution {
public:
    int n, m;

    int solve(vector<vector<vector<int>>>& dp,
              int i, int j1, int j2,
              vector<vector<int>>& grid) {

        // Invalid columns
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        // Last row
        if(i == n - 1) {

            if(j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

        // Already calculated
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int temp = -1e9;

        // 9 possible combinations
        for(int k = -1; k <= 1; k++) {

            for(int l = -1; l <= 1; l++) {

                int chocolates;

                if(j1 == j2)
                    chocolates = grid[i][j1];
                else
                    chocolates = grid[i][j1] + grid[i][j2];

                chocolates += solve(
                    dp,
                    i + 1,
                    j1 + k,
                    j2 + l,
                    grid
                );

                temp = max(temp, chocolates);
            }
        }

        return dp[i][j1][j2] = temp;
    }

    int maxChocolate(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m, -1)
            )
        );

        return solve(dp, 0, 0, m - 1, grid);
    }
};
