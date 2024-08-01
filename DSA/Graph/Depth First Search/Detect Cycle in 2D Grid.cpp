/*  Leetcode Link : https://leetcode.com/problems/detect-cycles-in-2d-grid/
    Difficulty : Medium
*/

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int prev_i, int prev_j) {
        visited[i][j] = true;

        for (vector<int>& dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];

            if (row >= 0 && row < m && col >= 0 && col < n && grid[i][j] == grid[row][col] && !(prev_i == row && prev_j == col))
                if (visited[row][col] || dfs(grid, visited, row, col, i, j))
                    return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        inc();

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && dfs(grid, visited, i, j, -1, -1))
                    return true;
            }
        }

        return false;
    }
};
