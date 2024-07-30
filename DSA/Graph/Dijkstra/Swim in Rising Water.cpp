/*  Leetcode Link : https://leetcode.com/problems/swim-in-rising-water/
    Difficulty: Hard
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        inc();
        int n = grid.size();

        if(n == 1)
            return grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int result = max(grid[0][0], grid[n - 1][n - 1]);

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        pq.push({result, 0, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int node = curr[0];
            int i = curr[1];
            int j = curr[2];

            result = max(result, node);
            for (vector<int>& dir : directions) {
                int row = i + dir[0];
                int col = j + dir[1];

                if (isValid(row, col, n) && !visited[row][col]) {
                    if (row == n - 1 && col == n - 1)
                        return result;

                    pq.push({grid[row][col], row, col});
                    visited[row][col] = true;
                }
            }
        }

        return -1;
    }
};
