// Recursion
// Time Complexity: Exponential
// Space Complexity: O(W) -> Recursion Stack

class Solution {
  public:
    int solve(int ind, int W,
              vector<int>& wt,
              vector<int>& val) {

        // Base Case
        if(ind == 0) {
            return (W / wt[0]) * val[0];
        }

        // Not Take
        int skip = solve(ind - 1, W, wt, val);

        // Take
        int take = 0;

        if(wt[ind] <= W)
            take = val[ind] +
                   solve(ind, W - wt[ind], wt, val);

        return max(skip, take);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int W) {

        int n = val.size();

        return solve(n - 1, W, wt, val);
    }
};


// Memoisation
// Time Complexity: O(N * W)
// Space Complexity: O(N * W) + O(W)
//                  DP Array + Recursion Stack

class Solution {
  public:
    int solve(int ind, int W,
              vector<int>& wt,
              vector<int>& val,
              vector<vector<int>>& dp) {

        // Base Case
        if(ind == 0) {
            return (W / wt[0]) * val[0];
        }

        // Already calculated
        if(dp[ind][W] != -1)
            return dp[ind][W];

        // Not Take
        int skip = solve(ind - 1, W, wt, val, dp);

        // Take
        int take = 0;

        if(wt[ind] <= W)
            take = val[ind] +
                   solve(ind, W - wt[ind], wt, val, dp);

        return dp[ind][W] = max(skip, take);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int W) {

        int n = val.size();

        vector<vector<int>> dp(
            n, vector<int>(W + 1, -1)
        );

        return solve(n - 1, W, wt, val, dp);
    }
};



// Tabulation
// Time Complexity: O(N * W)
// Space Complexity: O(N * W)

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {

        int n = val.size();

        vector<vector<int>> dp(
            n, vector<int>(W + 1, 0)
        );

        // Base Case: only item 0
        for(int w = 0; w <= W; w++) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        // DP
        for(int i = 1; i < n; i++) {

            for(int w = 0; w <= W; w++) {

                // Skip
                int skip = dp[i - 1][w];

                // Take
                int take = 0;

                if(wt[i] <= w)
                    take = val[i] +
                           dp[i][w - wt[i]];

                dp[i][w] = max(skip, take);
            }
        }

        return dp[n - 1][W];
    }
};



// Space-optimization -(2D)
// Time Complexity: O(N * W)
// Space Complexity: O(W)

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {

        int n = val.size();

        vector<int> prev(W + 1, 0);
        vector<int> curr(W + 1, 0);

        // Base Case
        for(int w = 0; w <= W; w++) {
            prev[w] = (w / wt[0]) * val[0];
        }

        for(int i = 1; i < n; i++) {

            for(int w = 0; w <= W; w++) {

                // Skip
                int skip = prev[w];

                // Take
                int take = 0;

                if(wt[i] <= w)
                    take = val[i] +
                           curr[w - wt[i]];

                curr[w] = max(skip, take);
            }

            prev = curr;
        }

        return prev[W];
    }
};




// Space-optimization -(1D)
// Time Complexity: O(N * W)
// Space Complexity: O(W)
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {

        int n = val.size();

        vector<int> prev(W + 1, 0);

        // Base Case
        for(int w = 0; w <= W; w++) {
            prev[w] = (int)(w / wt[0]) * val[0];
        }

        for(int i = 1; i < n; i++) {

            for(int w = 0; w <=W; w++) {

                // Skip
                int skip = prev[w];

                // Take
                int take = 0;

                if(wt[i] <= w)
                    take = val[i] +
                           prev[w - wt[i]];

                prev[w] = max(skip, take);
            }

        }

        return prev[W];
    
    }
};


