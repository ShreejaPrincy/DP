// TC: O(n)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int sell = prices[i];

            profit = max(profit, sell - buy);

            buy = min(buy, sell);
        }

        return profit;
    }
};
