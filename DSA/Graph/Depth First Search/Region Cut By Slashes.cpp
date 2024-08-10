/*  Leetcode Link : https://leetcode.com/problems/regions-cut-by-slashes/
    Difficulty : Medium
*/

// Time Complexity : O(9*m*n) -> O(m*n)
// Space Complexity : O(9*m*n) -> O(m*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    void netSlices(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n || matrix[i][j])
            return;

        matrix[i][j] = 1;

        for (vector<int>& dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];

            netSlices(matrix, row, col);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        inc();

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> matrix(3 * m, vector<int>(3 * n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        m = matrix.size();
        n = matrix[0].size();

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    netSlices(matrix, i, j);
                    result++;
                }
            }
        }

        return result;
    }
};
