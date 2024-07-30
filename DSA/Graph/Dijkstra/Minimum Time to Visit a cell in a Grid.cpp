// Leetcode Link : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int Dijkstra(vector<vector<int>>& grid, int i, int j) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({grid[i][j], i, j});

        while (!pq.empty()) {
            vector<int> node = pq.top();
            pq.pop();

            int time = node[0];
            int row = node[1];
            int col = node[2];

            if (row == m - 1 && col == n - 1)
                return time;

            if (visited[row][col])
                continue;

            visited[row][col] = true;

            for (vector<int>& dir : directions) {
                int newR = row + dir[0];
                int newC = col + dir[1];

                if (!isValid(newR, newC) || visited[newR][newC])
                    continue;

                int standBy = (grid[newR][newC] - time) % 2 == 0;
                pq.push({max(grid[newR][newC] + standBy, time + 1), newR, newC});
            }
        }

        return -1;
    }

    int minimumTime(vector<vector<int>>& grid) {
        inc();

        m = grid.size();
        n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        return Dijkstra(grid, 0, 0);
    }
};
