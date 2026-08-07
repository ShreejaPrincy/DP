// Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle) {

        // Base Case
        if (i == triangle.size() - 1)
            return triangle[i][j];

        int down = solve(i + 1, j, triangle);
        int diagonal = solve(i + 1, j + 1, triangle);

        return triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        return solve(0, 0, triangle);
    }
};



