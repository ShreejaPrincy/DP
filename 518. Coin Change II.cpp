// Recursion
// Time Complexity: Exponential
// Space Complexity: O(N + Amount) -> Recursion Stack

class Solution {
public:
    int solve(int i, int amount, vector<int>& coins) {

        if(amount == 0)
            return 1;

        if(i == 0) {
            if(amount % coins[i] == 0)
                return 1;
            else
                return 0;
        }

        int take = 0;

        if(amount - coins[i] >= 0)
            take = solve(i, amount - coins[i], coins);

        int skip = solve(i - 1, amount, coins);

        return take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        return solve(n - 1, amount, coins);
    }
};



//Memoization
// Time Complexity: O(N * Amount)
// Space Complexity: O(N * Amount) + O(N + Amount)
//                  DP Array    + Recursion Stack
// Overall Space: O(N * Amount)
class Solution {
public:
    int solve(vector<vector<int>>&dp,int i,int amount, vector<int>& coins){
        if(amount==0)   return 1;
        if(i==0){
            if(amount%coins[i]==0)  return 1;
            else                    return 0;
        }
        
        if(dp[i][amount]!=-1)   return dp[i][amount];

        int take=0;
        if(amount-coins[i]>=0)  take=solve(dp,i,amount-coins[i],coins);

        int skip=solve(dp,i-1,amount,coins);

        return dp[i][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(dp,n-1,amount,coins);
    }
};



//Tabulation
// Time Complexity: O(N * Amount)
// Space Complexity: O(N * Amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0) dp[0][amt]=1;
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                unsigned int take=0;
                if(amt-coins[i]>=0)  take=dp[i][amt-coins[i]];

                unsigned int skip=dp[i-1][amt];

                dp[i][amt]=take+skip;
            }
        }
        return dp[n-1][amount];
    }
};


//Space Optimisation
// Time Complexity: O(N * Amount)
// Space Complexity: O(Amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        //vector<vector<int>>dp(n,vector<int>(amount+1,0));

        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);

        prev[0]=1;
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0) prev[amt]=1;
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                unsigned int take=0;
                if(amt-coins[i]>=0)  take=curr[amt-coins[i]];

                unsigned int skip=prev[amt];

                curr[amt]=take+skip;
            }
            prev=curr;
        }
        return prev[amount];
    }
};

