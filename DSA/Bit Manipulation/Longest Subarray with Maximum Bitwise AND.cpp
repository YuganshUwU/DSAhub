/*  LeetCode link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
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
    int longestSubarray(vector<int>& nums) {
        inc();

        int maxVal = *max_element(nums.begin(), nums.end());
        int result = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal) {
                result++;
                count = max(count, result);
            } else {
                result = 0;
            }
        }

        return count;
    }
};
