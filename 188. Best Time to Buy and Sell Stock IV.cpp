// Space Optimisation
// TC: O(n*k)
// SC: O(k)
// similar to Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>front(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){

                    if(buy){
                        curr[buy][cap]=max(
                            -prices[i]+front[0][cap],
                            front[1][cap]
                        );
                    }
                    else{
                        curr[buy][cap]=max(
                            prices[i]+front[1][cap-1],
                            front[0][cap]
                        );
                    }
                }
            }

            front=curr;
        }

        return front[1][k];
    }
};
