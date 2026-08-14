// Recursion
// TC: O(2^(n+m)) approximately
// SC: O(n+m) -> Recursion stack

class Solution {
public:
    int solve(int i, int j, int& result, string& s1, string& s2) {

        if(i < 0 || j < 0)
            return 0;

        int curr = 0;

        if(s1[i] == s2[j]) {
            curr = 1 + solve(i-1, j-1, result, s1, s2);

            result = max(result, curr);
        }

        // Explore other possible starting positions
        solve(i, j-1, result, s1, s2);
        solve(i-1, j, result, s1, s2);

        return curr;
    }

    int longCommSubstr(string& s1, string& s2) {

        int n = s1.size();
        int m = s2.size();

        int result = 0;

        solve(n-1, m-1, result, s1, s2);

        return result;
    }
};








// Tabulation
// TC: O(n*m)
// SC: O(n*m)

// NOTE: Index Shifting
// We use dp[n+1][m+1] to avoid negative indices.
// dp[0][*] and dp[*][0] represent an empty string.
// So dp[i][j] corresponds to s1[i-1] and s2[j-1].

class Solution {
public:
    int longCommSubstr(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int result = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;

                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};





//Space Optimisation
// TC: O(n*m)
// SC: O(m)

// NOTE: Index Shifting
// We use i = 1 to n and j = 1 to m.
// Therefore, actual string indices are:
// s1[i-1] and s2[j-1].
// Extra 0th row/column represent an empty string.

class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {

        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        int result = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];

                else
                    curr[j] = 0;

                result = max(result, curr[j]);
            }

            prev = curr;
        }

        return result;
    }
};
