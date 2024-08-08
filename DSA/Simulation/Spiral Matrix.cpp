/*  Leetcode link : https://leetcode.com/problems/spiral-matrix/
    Difficulty : Medium
*/

// Time Complexity : O(m*n)
// Space Complexity :O(1) Excluding result vector

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        inc();

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        vector<int> result;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }

            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }

            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return result;
    }
};
