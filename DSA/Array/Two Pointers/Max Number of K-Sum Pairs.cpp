/*  LeetCode link : https://leetcode.com/problems/max-number-of-k-sum-pairs/
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
    int maxOperations(vector<int>& nums, int k) {
        inc();

        int result = 0;
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int curr = nums[left] + nums[right];

            if (curr == k) {
                result++;
                left++;
                right--;
            } else if (curr > k) {
                right--;
            } else
                left++;
                
        }

        return result;
    }
};
