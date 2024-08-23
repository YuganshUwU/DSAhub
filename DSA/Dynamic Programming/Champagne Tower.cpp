/*  LeetCode link : https://leetcode.com/problems/champagne-tower/
    Difficulty : Medium
*/

// Approach 1 - Recursion + Memoization
// Time Complexity : O(query_glass * query_row)
// Space Complexity : O(query_glass * query_row)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<double>> dp;

    double finding(int poured, int row, int col) {
        if (row < 0 || col < 0 || row < col)
            return 0.0;

        if (row == 0 && col == 0)
            return poured;

        if (dp[row][col] != -1.0)
            return dp[row][col];

        double up_left = (finding(poured, row - 1, col - 1) - 1) / 2.0;
        double up_right = (finding(poured, row - 1, col) - 1) / 2.0;

        up_left = up_left < 0 ? 0.0 : up_left;
        up_right = up_right < 0 ? 0.0 : up_right;

        return dp[row][col] = up_left + up_right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        inc();

        dp.resize(query_row + 1, vector<double>(query_glass + 1, -1.0));
        return min(1.0, finding(poured, query_row, query_glass));
    }
};

-------------------------------------------------------------------------------------------------------------------

// Approach 2 - Dynamic Programming
// Time Complexity : O(query_glass * query_row)
// Space Complexity : O(101 * 101)

          
  #define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        inc();

        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = (double)poured;

        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double extra = (dp[i][j] - 1) / 2.0;

                if (extra > 0) {
                    dp[i + 1][j] += extra;
                    dp[i + 1][j + 1] += extra;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};
