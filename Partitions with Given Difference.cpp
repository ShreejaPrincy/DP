// Formula:
// S1 + S2 = totsum
// S1 - S2 = diff
// Therefore:
// 2*S2 = totsum - diff
// target = (totsum - diff) / 2
//
// We now count subsets with sum = target.
//
// Time Complexity: O(n * target)
// Space Complexity: O(target)




// Approach: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n) - Recursion stack

class Solution {
public:

    int solve(int i, int target, vector<int>& arr) {

        if(i == 0) {
            if(target == 0 && arr[0] == 0)
                return 2;

            return (target == 0 || target == arr[0]) ? 1 : 0;
        }

        int take = 0;

        if(target >= arr[i])
            take = solve(i - 1, target - arr[i], arr);

        int skip = solve(i - 1, target, arr);

        return take + skip;
    }

    int countPartitions(vector<int>& arr, int diff) {

        int n = arr.size();

        int totsum = 0;

        for(int x : arr)
            totsum += x;

        if(totsum < diff || (totsum - diff) % 2 != 0)
            return 0;

        int target = (totsum - diff) / 2;

        return solve(n - 1, target, arr);
    }
};



// Approach: Memoization
// Time Complexity: O(n * target)
// Space Complexity: O(n * target) - DP table + O(n) recursion stack
// Overall Space Complexity: O(n * target)

class Solution {
public:

    int solve(vector<vector<int>>& dp, int i, int target,
              vector<int>& arr) {

        if(i == 0) {
            if(target == 0 && arr[0] == 0)
                return 2;

            return (target == 0 || target == arr[0]) ? 1 : 0;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        int take = 0;

        if(target >= arr[i])
            take = solve(dp, i - 1, target - arr[i], arr);

        int skip = solve(dp, i - 1, target, arr);

        return dp[i][target] = take + skip;
    }

    int countPartitions(vector<int>& arr, int diff) {

        int n = arr.size();

        int totsum = 0;

        for(int x : arr)
            totsum += x;

        if(totsum < diff || (totsum - diff) % 2 != 0)
            return 0;

        int target = (totsum - diff) / 2;

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        return solve(dp, n - 1, target, arr);
    }
};



// Approach: Tabulation
// Time Complexity: O(n * target)
// Space Complexity: O(n * target)

class Solution {
public:

    int countPartitions(vector<int>& arr, int diff) {

        int n = arr.size();

        int totsum = 0;

        for(int x : arr)
            totsum += x;

        if(totsum < diff || (totsum - diff) % 2 != 0)
            return 0;

        int target = (totsum - diff) / 2;

        vector<vector<int>> dp(
            n, vector<int>(target + 1, 0)
        );

        for(int i = 0; i < n; i++)
            dp[i][0] = 1;

        if(arr[0] == 0)
            dp[0][0] = 2;
        else if(arr[0] <= target)
            dp[0][arr[0]] = 1;

        for(int i = 1; i < n; i++) {

            for(int tar = 0; tar <= target; tar++) {

                int skip = dp[i - 1][tar];

                int take = 0;

                if(tar >= arr[i])
                    take = dp[i - 1][tar - arr[i]];

                dp[i][tar] = take + skip;
            }
        }

        return dp[n - 1][target];
    }
};



// Approach: Space Optimization
// Time Complexity: O(n * target)
// Space Complexity: O(target)

class Solution {
public:

    int countPartitions(vector<int>& arr, int diff) {

        int n = arr.size();

        int totsum = 0;

        for(int x : arr)
            totsum += x;

        if(totsum < diff || (totsum - diff) % 2 != 0)
            return 0;

        int target = (totsum - diff) / 2;

        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        if(arr[0] == 0)
            prev[0] = 2;
        else if(arr[0] <= target)
            prev[arr[0]] = 1;

        for(int i = 1; i < n; i++) {

            for(int tar = 0; tar <= target; tar++) {

                int skip = prev[tar];

                int take = 0;

                if(tar >= arr[i])
                    take = prev[tar - arr[i]];

                curr[tar] = take + skip;
            }

            prev = curr;
        }

        return prev[target];
    }
};
