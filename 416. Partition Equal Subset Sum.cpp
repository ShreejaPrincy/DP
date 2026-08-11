// Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:

    bool solve(int i, int target, vector<int>& arr) {

        // Target achieved
        if(target == 0)
            return true;

        // Only first element is left
        if(i == 0)
            return arr[0] == target;

        // Take current element
        bool take = false;

        if(arr[i] <= target) {
            take = solve(i - 1, target - arr[i], arr);
        }

        // Skip current element
        bool skip = solve(i - 1, target, arr);

        return take || skip;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums) {
            sum += x;
        }

        // Odd total cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        return solve(nums.size() - 1, target, nums);
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

        // Only first element is left
        if(i == 0)
            return arr[0] == target;

        // Already calculated
        if(dp[i][target] != -1)
            return dp[i][target];

        // Take current element
        bool take = false;

        if(arr[i] <= target) {
            take = solve(dp, i - 1, target - arr[i], arr);
        }

        // Skip current element
        bool skip = solve(dp, i - 1, target, arr);

        return dp[i][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums) {
            sum += x;
        }

        // Odd sum cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(dp, n - 1, target, nums);
    }
};



// Tabulation
// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
public:

    bool canPartition(vector<int>& arr) {

        int sum = 0;

        for(int x : arr) {
            sum += x;
        }

        // Odd sum cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = arr.size();

        vector<vector<bool>> dp(
            n,
            vector<bool>(target + 1, false)
        );

        // Sum 0 is always possible
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Using only arr[0]
        if(arr[0] <= target) {
            dp[0][arr[0]] = true;
        }

        // Fill DP table
        for(int i = 1; i < n; i++) {

            for(int tar = 1; tar <= target; tar++) {

                // Take
                bool take = false;

                if(arr[i] <= tar) {
                    take = dp[i-1][tar-arr[i]];
                }

                // Skip
                bool skip = dp[i-1][tar];

                dp[i][tar] = take || skip;
            }
        }

        return dp[n-1][target];
    }
};



