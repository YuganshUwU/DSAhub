/*  Leetcode link : https://leetcode.com/problems/maximum-number-of-points-with-cost/
    Difficulty : Medium
*/

// Approach 1 - Dynamic Programming
// Time Complexity : O(m*n*n)    TLE
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        inc();

        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n);

        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++) {
            vector<long long> curr(n);

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    curr[j] = max(curr[j], prev[k] + points[i][j] - abs(j - k));
                }
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};

--------------------------------------------------------------------------------------------------------------------------

// Approach 2 - Optimized Dynamic Programming
// Time Complexity : O(m*n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        inc();

        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n, 0);

        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++) {
            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            left[0] = prev[0];

            for (int j = 1; j < n; j++)
                left[j] = max(prev[j], left[j - 1] - 1);

            right[n - 1] = prev[n - 1];

            for (int j = n - 2; j >= 0; j--)
                right[j] = max(prev[j], right[j + 1] - 1);

            for (int j = 0; j < n; j++)
                prev[j] = points[i][j] + max(left[j], right[j]);
        }

        return *max_element(prev.begin(), prev.end());
    }
};
