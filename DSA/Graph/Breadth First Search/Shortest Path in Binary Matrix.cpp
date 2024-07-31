/*  Leetcode link : https://leetcode.com/problems/shortest-path-in-binary-matrix/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        inc();

        int n = grid.size();
        vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0},   {1, 1},  {0, 1},  {0, -1}};

        queue<vector<int>> que;
        if (grid[0][0] == 1)
            return -1;

        que.push({0, 0, 1});
        grid[0][0] = 1;

        while (!que.empty()) {
            vector<int> curr = que.front();
            que.pop();

            int i = curr[0];
            int j = curr[1];
            int path = curr[2];

            if (i == n - 1 && j == n - 1)
                return path;

            for (vector<int>& dir : directions) {
                int row = i + dir[0];
                int col = j + dir[1];

                if (row >= 0 && row < n && col >= 0 && col < n &&
                    !grid[row][col]) {
                    que.push({row, col, path + 1});
                    grid[row][col] = 1;
                }
            }
        }

        return -1;
    }
};
