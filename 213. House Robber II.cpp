// Memoization (Top-Down DP)
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// (DP array + recursion stack)

class Solution {
public:
    int solve(int s, int n, vector<int>& nums, vector<int>& dp) {
        if (n < s)
            return 0;

        if (n == s)
            return dp[n] = nums[s];

        if (dp[n] != -1)
            return dp[n];

        int take = nums[n] + solve(s, n - 2, nums, dp);
        int skip = solve(s, n - 1, nums, dp);

        return dp[n] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int withFirst = solve(0, n - 2, nums, dp1);
        int withoutFirst = solve(1, n - 1, nums, dp2);

        return max(withFirst, withoutFirst);
    }
};



// Tabulation (Bottom-Up DP)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int solve(int start, int end, vector<int>& nums, vector<int>& dp) {

        dp[start] = nums[start];

        for (int i = start + 1; i <= end; i++) {

            int take = nums[i];

            if (i - 2 >= start)
                take += dp[i - 2];

            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        int withFirst = solve(0, n - 2, nums, dp1);
        int withoutFirst = solve(1, n - 1, nums, dp2);

        return max(withFirst, withoutFirst);
    }
};


// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int solve(int s, int e, vector<int>& nums) {

        int prev1 = nums[s];
        int prev2 = 0;

        for (int i = s + 1; i <= e; i++) {

            int take = nums[i] + prev2;
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        int withFirst = solve(0, n - 2, nums);
        int withoutFirst = solve(1, n - 1, nums);

        return max(withFirst, withoutFirst);
    }
};


//--------------------------------------------------------------------
//striver's code
// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(n)
// (O(n) for temp1 and temp2, O(1) extra space in the helper function)

class Solution {
public:
    int solve(vector<int>& nums) {

        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < nums.size(); i++) {

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

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {

            if (i != n - 1)
                temp1.push_back(nums[i]);

            if (i != 0)
                temp2.push_back(nums[i]);
        }

        return max(solve(temp1), solve(temp2));
    }
};
