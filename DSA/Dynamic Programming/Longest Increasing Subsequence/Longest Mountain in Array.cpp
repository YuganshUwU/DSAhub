/*  LeetCode link : https://leetcode.com/problems/longest-mountain-in-array/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int longestMountain(vector<int>& nums) {
        INC();

        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                LIS[i] = max(LIS[i], LIS[i - 1] + 1);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                LDS[i] = max(LDS[i], LDS[i + 1] + 1);
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1)
                result = max(result, LIS[i] + LDS[i] - 1);
        }

        return result;
    }
};

-----------------------------------------------------------------------------------------------------------------

// Time Complexity : O(n)
// Space Complexity : O(1)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int longestMountain(vector<int>& nums) {
        INC();

        int n = nums.size();
        int result = 0;

        int up = 0, down = 0;

        for (int i = 1; i < n; i++) {
            if ((down && nums[i] > nums[i - 1]) || nums[i] == nums[i - 1]) {
                up = 0;
                down = 0;
            }

            if (nums[i] > nums[i - 1])
                up++;

            if (nums[i] < nums[i - 1])
                down++;

            if (up && down)
                result = max(result, up + down + 1);
        }

        return result;
    }
};
