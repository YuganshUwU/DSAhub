/*  Leetcode Link : https://leetcode.com/problems/01-matrix/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        inc();

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!mat[i][j]) {
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while (!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();
            int row = curr.first;
            int col = curr.second;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && result[newRow][newCol] == -1) {
                    result[newRow][newCol] = result[row][col] + 1;
                    que.push({newRow, newCol});
                }
            }
            
        }

        return result;
    }
};
