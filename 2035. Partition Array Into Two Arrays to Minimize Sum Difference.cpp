// Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    int n;

    int solve(int i, int count, int sum1,
              int totalSum, vector<int>& nums) {

        // Exactly n/2 elements selected
        if(count == n / 2) {
            int sum2 = totalSum - sum1;
            return abs(sum1 - sum2);
        }

        // No elements left
        if(i == n)
            return 1e9;

        // Take current element
        int take = solve(
            i + 1,
            count + 1,
            sum1 + nums[i],
            totalSum,
            nums
        );

        // Skip current element
        int skip = solve(
            i + 1,
            count,
            sum1,
            totalSum,
            nums
        );

        return min(take, skip);
    }

    int minimumDifference(vector<int>& nums) {

        n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        return solve(0, 0, 0, totalSum, nums);
    }
};



// Memoization
// Time Complexity: O(number of states × log(number of states))
// Space Complexity: O(number of states) + O(n)

class Solution {
public:
    int n;

    int solve(map<tuple<int,int,int>, int>& dp,
              int i,
              int count,
              int sum1,
              int totalSum,
              vector<int>& nums) {

        // Exactly n/2 elements selected
        if(count == n / 2) {
            int sum2 = totalSum - sum1;
            return abs(sum1 - sum2);
        }

        // No elements left
        if(i == n)
            return 1e9;

        // Already calculated
        if(dp.find({i, count, sum1}) != dp.end())
            return dp[{i, count, sum1}];

        // Take
        int take = solve(
            dp,
            i + 1,
            count + 1,
            sum1 + nums[i],
            totalSum,
            nums
        );

        // Skip
        int skip = solve(
            dp,
            i + 1,
            count,
            sum1,
            totalSum,
            nums
        );

        return dp[{i, count, sum1}] = min(take, skip);
    }

    int minimumDifference(vector<int>& nums) {

        n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        map<tuple<int,int,int>, int> dp;

        return solve(dp, 0, 0, 0, totalSum, nums);
    }
};



