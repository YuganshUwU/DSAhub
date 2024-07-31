/*  Leetcode Link : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        inc();

        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> que;

        que.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while (!que.empty()) {
            vector<int> curr = que.front();
            que.pop();

            int i = curr[0];
            int j = curr[1];
            int steps = curr[2];

            if ((i != entrance[0] || j != entrance[1]) && (!i || !j || i == m - 1 || j == n - 1))
                return steps;

            for (vector<int>& dir : directions) {
                int row = i + dir[0];
                int col = j + dir[1];

                if (row >= 0 && row < m && col >= 0 && col < n &&
                    maze[row][col] == '.') {
                    que.push({row, col, steps + 1});
                    maze[row][col] = '+';
                }
            }
        }

        return -1;
    }
};
