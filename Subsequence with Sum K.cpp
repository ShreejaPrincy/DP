// Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n) recursion stack

class Solution {
public:

    bool solve(int i,
               int target,
               vector<int>& arr) {

        // Target achieved
        if(target == 0)
            return true;

        // Only one element left
        if(i == 0)
            return target == arr[i];

        // Take
        bool take = false;

        if(target >= arr[i])
            take = solve(
                i - 1,
                target - arr[i],
                arr
            );

        // Skip
        bool skip = solve(
            i - 1,
            target,
            arr
        );

        return take || skip;
    }

    bool checkSubsequenceSum(vector<int>& arr, int target) {

        int n = arr.size();

        return solve(n - 1, target, arr);
    }
};



// Memoization
// Time Complexity: O(n * target)
// Space Complexity: O(n * target) + O(n) recursion stack
// Overall Space Complexity: O(n * target)

class Solution {
public:

    bool solve(vector<vector<int>>& dp,
               int i,
               int target,
               vector<int>& arr) {

        // Target achieved
        if(target == 0)
            return true;

        // Only one element left
        if(i == 0)
            return target == arr[i];

        // Already calculated
        if(dp[i][target] != -1)
            return dp[i][target];

        // Take
        bool take = false;

        if(target >= arr[i])
            take = solve(dp, i - 1,
                         target - arr[i], arr);

        // Skip
        bool skip = solve(dp, i - 1,
                          target, arr);

        return dp[i][target] = take || skip;
    }

    bool checkSubsequenceSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(dp, n - 1, target, arr);
    }
};




// Tabulation
// Time Complexity: O(n * k)
// Space Complexity: O(n * k)

class Solution {
public:

    bool checkSubsequenceSum(vector<int>& arr, int k) {

        int n = arr.size();

        if(n == 0)
            return k == 0;

        vector<vector<bool>> dp(
            n,
            vector<bool>(k + 1, false)
        );

        // Sum 0 can always be formed
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Using only arr[0]
        if(arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        // Fill the table
        for(int i = 1; i < n; i++) {

            for(int target = 1; target <= k; target++) {

                // Skip current element
                bool skip = dp[i - 1][target];

                // Take current element
                bool take = false;

                if(target >= arr[i]) {
                    take = dp[i - 1][target - arr[i]];
                }

                dp[i][target] = take || skip;
            }
        }

        return dp[n - 1][k];
    }
};



