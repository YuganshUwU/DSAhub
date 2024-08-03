/*  Leetcode link : https://leetcode.com/problems/next-permutation/
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
    void nextPermutation(vector<int>& nums) {
        inc();

        int n = nums.size();

        int curr_idx = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                curr_idx = i - 1;
                break;
            }
        }

        if (curr_idx != -1) {
            int swap_idx = curr_idx;

            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[curr_idx]) {
                    swap_idx = i;
                    break;
                }
            }

            swap(nums[curr_idx], nums[swap_idx]);
        }

        reverse(nums.begin() + curr_idx + 1, nums.end());
    }
};
