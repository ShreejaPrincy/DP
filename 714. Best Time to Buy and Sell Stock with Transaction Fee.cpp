/*
Stock II → Stock with Transaction Fee, the main change is:

// Stock II
prices[i] + front[1]


// With Fee
prices[i] + front[1] - fee

*/

// Space Optimisation
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n=nums.size();

        vector<int>curr(2,0),front(2,0);

        front[0]=front[1]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy]=max(
                        -nums[i]+front[0],
                        front[1]
                    );
                }
                else{
                    curr[buy]=max(
                        nums[i]+front[1]-fee,
                        front[0]
                    );
                }
            }

            front=curr;
        }

        return front[1];
    }
};
