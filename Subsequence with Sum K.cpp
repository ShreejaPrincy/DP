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




