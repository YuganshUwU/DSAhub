/*  LeetCode link : https://leetcode.com/problems/longest-increasing-subsequence/description/
    Difficulty : Medium
*/

// Time Complexity : O(n * n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        inc();

        int n = nums.size();
        vector<int> result(n, 1);
        int ans = 0;

        if (n <= 1)
            return n;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {

                if (nums[i] > nums[j]) {
                    result[i] = max(result[i], result[j] + 1);
                }
            }

            ans = max(ans, result[i]);
        }

        return ans;
    }
};
