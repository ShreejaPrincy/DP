//Recursion
// Time Complexity: O(2^(N + Amount)) approximately
// Space Complexity: O(N + Amount) -> Recursion Stack

class Solution {
public:
    int n;

    int solve(int i, vector<int>& coins, int amount) {

        // Base Case
        if(i < 0) {
            if(amount != 0)
                return 1e9;

            return 0;
        }

        if(amount == 0)
            return 0;

        // Take
        int take = 1e9;

        if(coins[i] <= amount)
            take = 1 + solve(i, coins, amount - coins[i]);

        // Skip
        int skip = solve(i - 1, coins, amount);

        return min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();

        int ans = solve(n - 1, coins, amount);

        if(ans == 1e9)
            return -1;

        return ans;
    }
};


// Memoisation
// Time Complexity: O(N * Amount)
// Space Complexity: O(N * Amount) -> DP Array
//                    O(N)          -> Recursion Stack
// Overall Space: O(N * Amount)

class Solution {
public:

    int n;

    int solve(vector<vector<int>>& dp, int i,
              vector<int>& coins, int amount) {

        // Base Case
        if(amount == 0)
            return 0;

        if(i < 0)
            return 1e9;

        // Already calculated
        if(dp[i][amount] != -1)
            return dp[i][amount];

        // Take
        int take = 1e9;

        if(coins[i] <= amount) {
            take = 1 + solve(dp, i, coins,
                            amount - coins[i]);
        }

        // Skip
        int skip = solve(dp, i - 1, coins, amount);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(dp, n - 1, coins, amount);

        if(ans == 1e9)
            return -1;

        return ans;
    }
};


// Tabulation
// Time Complexity: O(N * Amount)
// Space Complexity: O(N * Amount)

class Solution {
public:
    int n;

    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base Case: amount = 0
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        // Base Case: only coin[0]
        for(int amt = 1; amt <= amount; amt++) {

            if(coins[0] > amt)
                dp[0][amt] = 1e9;
            else
                dp[0][amt] = 1 + dp[0][amt - coins[0]];
        }

        // DP
        for(int i = 1; i < n; i++) {

            for(int amt = 1; amt <= amount; amt++) {

                // Take
                int take = 1e9;

                if(coins[i] <= amt)
                    take = 1 + dp[i][amt - coins[i]];

                // Skip
                int skip = dp[i - 1][amt];

                dp[i][amt] = min(take, skip);
            }
        }

        int ans = dp[n - 1][amount];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};



//Space optimisation - 1D 
// Time Complexity: O(N * Amount)
// Space Complexity: O(Amount)

// 0/1 Knapsack:
// RIGHT → LEFT because current item must NOT be reused.

// Coin Change / Unbounded Knapsack:
// LEFT → RIGHT because current coin CAN be reused.

class Solution {
public:
    int n;

    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();

        vector<int> prev(amount + 1, 1e9);

        // Base Case
        prev[0] = 0;

        // Only coin[0]
        for(int amt = 1; amt <= amount; amt++) {

            if(coins[0] <= amt)
                prev[amt] = 1 + prev[amt - coins[0]];
        }

        // DP
        for(int i = 1; i < n; i++) {

            // *** IMPORTANT: LEFT → RIGHT
            for(int amt = 0; amt <= amount; amt++) {

                // Take
                int take = 1e9;

                if(coins[i] <= amt)
                    take = 1 + prev[amt - coins[i]];

                // Skip
                int skip = prev[amt];

                prev[amt] = min(take, skip);
            }
        }

        int ans = prev[amount];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};
