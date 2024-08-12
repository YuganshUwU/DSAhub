/*  Leetcode link : https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        inc();

        int result = 0;
        int sx = startPos[0], sy = startPos[1];
        int hx = homePos[0], hy = homePos[1];

        for (int i = hx; i != sx; i += (i < sx) ? 1 : -1)
            result += rowCosts[i];

        for (int i = hy; i != sy; i += (i < sy) ? 1 : -1)
            result += colCosts[i];

        return result;
    }
};
