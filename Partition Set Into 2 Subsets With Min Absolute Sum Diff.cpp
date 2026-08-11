// Approach: DP - Space Optimization
// Time Complexity: O(n * totalSum)
// Space Complexity: O(totalSum)

class Solution {
public:
    int minDifference(vector<int>& arr) {

        int n = arr.size();

        int totalSum = 0;

        for(int x : arr)
            totalSum += x;

        vector<bool> prev(totalSum + 1, false);
        vector<bool> curr(totalSum + 1, false);

        prev[0] = true;

        if(arr[0] <= totalSum)
            prev[arr[0]] = true;

        for(int i = 1; i < n; i++) {

            for(int target = 0; target <= totalSum; target++) {

                // Skip
                bool skip = prev[target];

                // Take
                bool take = false;

                if(arr[i] <= target)
                    take = prev[target - arr[i]];

                curr[target] = take || skip;
            }

            prev = curr;
        }

        int ans = INT_MAX;

        // S1 + S2 = totalSum
        // Difference = |S1 - S2|
        // = |totalSum - 2*S1|

        for(int s1 = 0; s1 <= totalSum / 2; s1++) {

            if(prev[s1]) {
                ans = min(ans, totalSum - 2 * s1);
            }
        }

        return ans;
    }
};
