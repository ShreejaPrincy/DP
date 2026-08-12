// Recursion
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



// Memoisation
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



// Tabulation
// Time Complexity: O(N * W)
// Space Complexity: O(N * W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=W;i++){
            if(wt[0]<=i)    dp[0][i]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                
                int skip=dp[i-1][w];
                int take=-1e9;
                if(wt[i]<=w)  take=val[i]+dp[i-1][w-wt[i]];
                 
                dp[i][w]=max(skip,take);
            }
        }
        
        return dp[n-1][W];
    }
};



// Space-optimization -(2D)
// Time Complexity: O(N * W)
// Space Complexity: O(W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        
        prev[0]=0;
        curr[0]=0;
        
        for(int i=0;i<=W;i++){
            if(wt[0]<=i)    prev[i]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                
                int skip=prev[w];
                int take=-1e9;
                if(wt[i]<=w)  take=val[i]+prev[w-wt[i]];
                 
                curr[w]=max(skip,take);
            }
            prev=curr;
        }
        
        return prev[W];
    }
};


// Space-optimization -(1D)
// Time Complexity: O(N * W)
// Space Complexity: O(W)

// 🔥 KEY 1D DP POINT:
//
// prev[w] = max(
//     prev[w],                      // Don't take current item
//     val[i] + prev[w - wt[i]]      // Take current item
// );
//
// IMPORTANT:
// We iterate w from RIGHT → LEFT:
//
// for(int w = W; w >= 0; w--)
//
// Why?
// Because prev[w - wt[i]] must be the OLD value
// (before using the current item).
//
// Going backwards ensures the smaller index
// w - wt[i] has NOT been updated yet.
//
// Hence, the same item cannot be taken twice.
//
// 0/1 Knapsack → RIGHT to LEFT


class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        vector<int> prev(W + 1, 0);

        // Base Case
        for(int w = 0; w <= W; w++) {
            if(wt[0] <= w)
                prev[w] = val[0];
        }

        // Fill DP
        for(int i = 1; i < n; i++) {

            // Traverse backwards
            for(int w = W; w >= 0; w--) {

                // Not Take
                int skip = prev[w];

                // Take
                int take = -1e9;

                if(wt[i] <= w)
                    take = val[i] + prev[w - wt[i]];

                prev[w] = max(skip, take);
            }
        }

        return prev[W];
    }
};


