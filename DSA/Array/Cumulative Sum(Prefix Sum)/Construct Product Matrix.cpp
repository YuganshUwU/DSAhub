/*  Leetcode link : https://leetcode.com/problems/construct-product-matrix/
    Difficulty : Medium
*/

// Time Complexity : O(m*n) 
// Space Complexity :O(1) (except returned value)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        inc();

        int n = grid.size();
        int m = grid[0].size();

        long long pref = 1, suff = 1;
        int MOD = 12345;

        vector<vector<int>> result(n, vector<int>(m, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (pref * result[i][j]) % MOD;
                result[n - i - 1][m - j - 1] = (suff * result[n - i - 1][m - j - 1]) % MOD;
                pref = (pref * grid[i][j]) % MOD;
                suff = (suff * grid[n - i - 1][m - j - 1]) % MOD;
            }
        }

        return result;
    }
};
