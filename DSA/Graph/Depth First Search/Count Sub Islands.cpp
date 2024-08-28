/*  LeetCode link : https://leetcode.com/problems/count-sub-islands/
    Difficulty : Medium
*/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& count) {
        if (i < 0 || i == m || j < 0 || j == n || !grid2[i][j])
            return;

        if (grid1[i][j] == 0 && grid2[i][j])
            count = 0;

        grid2[i][j] = 0;

        for (vector<int>& dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];

            dfs(grid1, grid2, row, col, count);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        inc();

        m = grid1.size();
        n = grid1[0].size();

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j]) {
                    int curr = 1;
                    dfs(grid1, grid2, i, j, curr);
                    result += curr;
                }
                
            }
        }

        return result;
    }
};
