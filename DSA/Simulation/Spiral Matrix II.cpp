/*  Leetcode link : https://leetcode.com/problems/spiral-matrix-ii/
    Difficulty : Medium
*/

// Time Complexity : O(m*n)
// Space Complexity : O(1) Excluding result vector

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        inc();

        vector<vector<int>> result(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                result[top][i] = val++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result[i][right] = val++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = val++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = val++;
                }
                left++;
            }
        }

        return result;
    }
};
