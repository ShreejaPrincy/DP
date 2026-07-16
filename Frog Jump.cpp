// Memoization (Top-Down DP)
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// (DP array + recursion stack)

class Solution {
public:
    int solve(int n, vector<int>& height, vector<int>& dp) {
        if (n == 0)
            return dp[0]=0;

        if (dp[n] != -1)
            return dp[n];

        int onestep = solve(n - 1, height, dp) + abs(height[n] - height[n - 1]);

        int twostep = INT_MAX;
        if (n > 1)
            twostep = solve(n - 2, height, dp) + abs(height[n] - height[n - 2]);

        return dp[n] = min(onestep, twostep);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);

        return solve(n - 1, height, dp);
    }
};


// Tabulation (Bottom-Up DP)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minCost(vector<int>& height) {

        int n = height.size();

        if (n == 1)
            return 0;

        vector<int> dp(n, -1);

        dp[0] = 0;
        dp[1] = abs(height[0] - height[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = min(
                dp[i - 1] + abs(height[i] - height[i - 1]),
                dp[i - 2] + abs(height[i] - height[i - 2])
            );
        }

        return dp[n - 1];
    }
};


// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minCost(vector<int>& height) {

        int n = height.size();

        if (n == 1)
            return 0;

        int prev2 = 0;
        int prev1 = abs(height[0] - height[1]);

        for (int i = 2; i < n; i++) {
            int curr = min(
                prev1 + abs(height[i] - height[i - 1]),
                prev2 + abs(height[i] - height[i - 2])
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
