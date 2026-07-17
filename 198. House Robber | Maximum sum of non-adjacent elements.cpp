// Memoization (Top-Down DP)
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// (DP array + recursion stack)

#include <bits/stdc++.h>

int solve(int n, vector<int>& nums, vector<int>& dp) {
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int take = nums[n] + solve(n - 2, nums, dp);
    int skip = solve(n - 1, nums, dp);

    return dp[n] = max(take, skip);
}

int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, -1);

    return solve(n - 1, nums, dp);
}


// Tabulation (Bottom-Up DP)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {

        int take = nums[i];
        if (i > 1)
            take += dp[i - 2];

        int skip = dp[i - 1];

        dp[i] = max(take, skip);
    }

    return dp[n - 1];
}


// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums) {

    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {

        int take = nums[i];
        if (i > 1)
            take += prev2;

        int skip = prev1;

        int curr = max(take, skip);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
