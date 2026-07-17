// Memoization (Top-Down DP)
// Time Complexity: O(n * k)
// Space Complexity: O(n) + O(n) = O(n)
// (DP array + recursion stack)

class Solution {
public:
    int solve(int n, vector<int>& arr, int k, vector<int>& dp) {
        if (n == 0)
            return dp[0] = 0;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (n - j >= 0) {
                dp[n] = min(dp[n],
                            abs(arr[n] - arr[n - j]) +
                            solve(n - j, arr, k, dp));
            }
        }

        return dp[n];
    }

    int frogjump(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return solve(n - 1, arr, k, dp);
    }
};


// Tabulation (Bottom-Up DP)
// Time Complexity: O(n * k)
// Space Complexity: O(n)

class Solution {
public:
    int frogjump(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;

            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i],
                                dp[i - j] +
                                abs(arr[i] - arr[i - j]));
                }
            }
        }

        return dp[n - 1];
    }
};
