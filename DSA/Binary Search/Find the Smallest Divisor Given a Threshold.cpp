/*  LeetCode link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
    Difficulty : Medium
*/

// Time Complexity : O(n log(max element))
// Space Complexity : O(1)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int find(vector<int>& nums, int val) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += (nums[i] + val - 1) / val;
        }

        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        INC();

        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int curr = find(nums, mid);

            if (curr > threshold) {
                l = mid + 1;
            } else {
                result = mid;
                r = mid - 1;
            }
        }

        return result;
    }
};
