// same (Count Partitions with Given Difference)
// Time Complexity: O(N * Target)
// Space Complexity: O(Target)
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
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};
