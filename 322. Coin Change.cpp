//Recursion
// Time Complexity: Exponential
// Space Complexity: O(N) -> Recursion Stack

class Solution {
public:

    int solve(int ind, int T, vector<int>& nums) {

        // Base Case
        if(ind == 0) {

            if(T % nums[0] == 0)
                return T / nums[0];

            return 1e9;
        }

        // Not Take
        int notTake = solve(ind - 1, T, nums);

        // Take
        int take = 1e9;

        if(nums[ind] <= T)
            take = 1 + solve(ind, T - nums[ind], nums);

        return min(take, notTake);
    }

    int minimumElements(vector<int>& nums, int target) {

        int n = nums.size();

        int ans = solve(n - 1, target, nums);

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};


// Memoisation
// Time Complexity: O(N * Target)
// Space Complexity: O(N * Target) -> DP Array
//                    O(N)         -> Recursion Stack
// Overall Space: O(N * Target)

class Solution {
public:

    int solve(int ind, int T, vector<int>& nums,
              vector<vector<int>>& dp) {

        // Base Case
        if(ind == 0) {

            if(T % nums[0] == 0)
                return T / nums[0];

            return 1e9;
        }

        // Already calculated
        if(dp[ind][T] != -1)
            return dp[ind][T];

        // Not Take
        int notTake = solve(ind - 1, T, nums, dp);

        // Take
        int take = 1e9;

        if(nums[ind] <= T)
            take = 1 + solve(ind, T - nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }

    int minimumElements(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        int ans = solve(n - 1, target, nums, dp);

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};

// Tabulation
// Time Complexity: O(N * Target)
// Space Complexity: O(N * Target)

class Solution {
public:

    int minimumElements(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(target + 1, 1e9)
        );

        // Base Case: ind == 0
        for(int T = 0; T <= target; T++) {

            if(T % nums[0] == 0)
                dp[0][T] = T / nums[0];
        }

        // Fill DP table
        for(int ind = 1; ind < n; ind++) {

            for(int T = 0; T <= target; T++) {

                // Not Take
                int notTake = dp[ind - 1][T];

                // Take
                int take = 1e9;

                if(nums[ind] <= T)
                    take = 1 + dp[ind][T - nums[ind]];

                dp[ind][T] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][target];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};




//Space Optimisation - 2D
// Time Complexity: O(N * Target)
// Space Complexity: O(Target)

class Solution {
public:

    int minimumElements(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> prev(target + 1, 1e9);
        vector<int> curr(target + 1, 1e9);

        // Base Case: ind == 0
        for(int T = 0; T <= target; T++) {

            if(T % nums[0] == 0)
                prev[T] = T / nums[0];
        }

        // Fill DP
        for(int ind = 1; ind < n; ind++) {

            for(int T = 0; T <= target; T++) {

                // Not Take
                int notTake = prev[T];

                // Take
                int take = 1e9;

                if(nums[ind] <= T)
                    take = 1 + curr[T - nums[ind]];

                curr[T] = min(take, notTake);
            }

            prev = curr;
        }

        int ans = prev[target];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};





//Space optimisation - 1D 
// Time Complexity: O(N * Amount)
// Space Complexity: O(Amount)

// 0/1 Knapsack:
// RIGHT → LEFT because current item must NOT be reused.

// Coin Change / Unbounded Knapsack:
// LEFT → RIGHT because current coin CAN be reused.

// Time Complexity: O(N * Target)
// Space Complexity: O(Target)

class Solution {
public:
    int minimumElements(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> prev(target + 1, 1e9);

        // Base Case: ind == 0
        for(int T = 0; T <= target; T++) {
            if(T % nums[0] == 0)
                prev[T] = T / nums[0];
        }

        for(int ind = 1; ind < n; ind++) {

            for(int T = 0; T <= target; T++) {

                // Not Take
                int notTake = prev[T];

                // Take
                int take = 1e9;

                if(nums[ind] <= T)
                    take = 1 + prev[T - nums[ind]];

                prev[T] = min(take, notTake);
            }
        }

        int ans = prev[target];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};
