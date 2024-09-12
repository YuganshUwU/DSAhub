/*  LeetCode link : https://leetcode.com/problems/maximum-alternating-subsequence-sum/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n * 2)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    long long dp[100001][2];

    long long finding(vector<int>& nums, int idx, bool sign) {
        if (idx == n)
            return 0;

        if(dp[idx][sign] != -1)
            return dp[idx][sign];

        bool takeSign = !sign;
        int val = sign ? 1 : -1;

        long long take = val * nums[idx] + finding(nums, idx + 1, takeSign);
        long long skip = finding(nums, idx + 1, sign);

        return dp[idx][sign] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        inc();

        memset(dp, -1, sizeof(dp));
        n = nums.size();
        
        return finding(nums, 0, true);
    }
};
