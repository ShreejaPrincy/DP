// Time Complexity: O(2^N)
// Space Complexity: O(N)  -> Recursion Stack

class Solution {
public:
    int solve(int ind, int W, vector<int>& wt, vector<int>& val) {

        // Base Case
        if (ind == 0) {
            if (wt[0] <= W)
                return val[0];

            return 0;
        }

        // Not Take
        int notTake = solve(ind - 1, W, wt, val);

        // Take
        int take = 0;

        if (wt[ind] <= W) {
            take = val[ind] +
                   solve(ind - 1, W - wt[ind], wt, val);
        }

        return max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        return solve(n - 1, W, wt, val);
    }
};



// Time Complexity: O(N * W)
// Space Complexity: O(N * W) -> DP Array
//                    O(N)     -> Recursion Stack
// Overall Space: O(N * W)

class Solution {
public:
    int solve(int ind, int W,
              vector<int>& wt,
              vector<int>& val,
              vector<vector<int>>& dp) {

        // Base Case
        if (ind == 0) {
            if (wt[0] <= W)
                return val[0];

            return 0;
        }

        // Already calculated
        if (dp[ind][W] != -1)
            return dp[ind][W];

        // Not Take
        int notTake = solve(ind - 1, W, wt, val, dp);

        // Take
        int take = 0;

        if (wt[ind] <= W) {
            take = val[ind] +
                   solve(ind - 1, W - wt[ind], wt, val, dp);
        }

        return dp[ind][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return solve(n - 1, W, wt, val, dp);
    }
};
