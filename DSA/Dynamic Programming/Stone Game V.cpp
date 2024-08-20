/*  LeetCode link : https://leetcode.com/problems/stone-game-v/
    Difficulty : Hard
*/

// Approach 1 : Recursion + Memoization
// Time Complexity :O(n * n)      Space Complexity : O(n * n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    // prefix sum to get the sum value from left to mid and mid + 1 to right in
    // constant time -> O(n)

    int dp[501][501];

    int finding(vector<int>& stone, int left, int right) {
        if (left >= right)
            return 0;

        if(dp[left][right] != -1)
            return dp[left][right];

        int result = INT_MIN;

        for (int i = left; i <= right; i++) {

            int leftSum = stone[i] - ((left != 0) ? stone[left - 1] : 0);
            int rightSum = stone[right] - stone[i];

            if (leftSum > rightSum)
                result = max(result, rightSum + finding(stone, i + 1, right));
            else if (leftSum < rightSum)
                result = max(result, leftSum + finding(stone, left, i));
            else
                result = max({result, rightSum + finding(stone, i + 1, right), finding(stone, left, i)});
        }

        return dp[left][right] = result;
    }

    int stoneGameV(vector<int>& stoneValue) {
        inc();

        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i < n; i++)
            stoneValue[i] += stoneValue[i - 1];

        // 6,2,3,4,5,5
        // the pref sum = 6,8,11,15,20,25

        return finding(stoneValue, 0, n - 1);
    }
};
