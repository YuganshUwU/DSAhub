/*  Leetcode Link : https://leetcode.com/problems/path-with-minimum-effort/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        inc();

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        vector<vector<int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int wt = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (i == m - 1 && j == n - 1)
                return wt;

            for (vector<int>& dir : directions) {
                int row = i + dir[0];
                int col = j + dir[1];

                if (isValid(row, col, m, n)) {
                    int value = max(wt, abs(heights[i][j] - heights[row][col]));

                    if (dist[row][col] > value) {
                        dist[row][col] = value;
                        pq.push({value, row, col});
                    }
                }
                
            }
        }

        return -1;
    }
};
