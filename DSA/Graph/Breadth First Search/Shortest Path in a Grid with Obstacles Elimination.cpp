/*  Leetcode Link : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
    Difficulty: Hard
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        inc();

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int visited[41][41][1601];
        memset(visited, false, sizeof(visited));
        queue<vector<int>> que;
        int result = 0;

        que.push({0, 0, k});
        visited[0][0][k] = true;

        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                vector<int> curr = que.front();
                que.pop();

                int i = curr[0];
                int j = curr[1];
                int obs = curr[2];

                if (i == m - 1 && j == n - 1)
                    return result;

                for (vector<int>& dir : directions) {
                    int row = i + dir[0];
                    int col = j + dir[1];

                    if (row < 0 || row >= m || col < 0 || col >= n)
                        continue;

                    if (!grid[row][col] && !visited[row][col][obs]) {
                        que.push({row, col, obs});
                        visited[row][col][obs] = true;
                    } else if (grid[row][col] && obs > 0 && !visited[row][col][obs - 1]) {
                        que.push({row, col, obs - 1});
                        visited[row][col][obs - 1] = true;
                    }
                }
            }

            result++;
        }

        return -1;
    }
};
