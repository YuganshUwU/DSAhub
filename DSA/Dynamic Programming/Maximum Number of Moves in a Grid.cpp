/*  LeetCode link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
    Difficulty : Medium
*/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    int dp[1001][1001];

    int finding(int row, int col, vector<vector<int>>& grid, int prev) {
        if (col < 0 || row < 0 || col >= n || row >= m)
            return 0;

        if (grid[row][col] <= prev)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        prev = grid[row][col];

        int diagUp = finding(row - 1, col + 1, grid, prev);
        int diagDown = finding(row + 1, col + 1, grid, prev);
        int diagStraight = finding(row, col + 1, grid, prev);

        return dp[row][col] = 1 + max({diagUp, diagDown, diagStraight});
    }

    int maxMoves(vector<vector<int>>& grid) {
        INC();

        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(result, finding(i, 0, grid, -1));
        }

        return result - 1;
    }
};
