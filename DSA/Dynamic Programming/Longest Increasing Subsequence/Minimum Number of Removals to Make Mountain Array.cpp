/*  LeetCode link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
    Difficulty : Hard
*/

// Time Complexity : O(n * m)
// Space Complexity : O(n)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        INC();

        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j])
                    LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }

        int result = n;

        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1)
                result = min(result, n - LIS[i] - LDS[i] + 1);
        }

        return result;
    }
};
