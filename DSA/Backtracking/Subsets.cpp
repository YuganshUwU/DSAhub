/*  Leetcode Link : https://leetcode.com/problems/subsets/
    Difficulty : Medium
*/

// Time Complexity : O(2^n)
// Space Complexity : O(2^n * n)

#define inc                                                                    \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;

    void finding(vector<int>& nums, int i, vector<int>& temp) {
        if (i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        finding(nums, i + 1, temp);

        temp.pop_back();
        finding(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        inc;

        vector<int> temp;
        finding(nums, 0, temp);
        return result;
    }
};
