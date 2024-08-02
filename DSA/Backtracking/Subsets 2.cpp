/*  Leetcode Link : https://leetcode.com/problems/subsets-ii/
    Difficulty : Medium
*/

// Time Complexity : O(2^n * n(logn))
// Space Complexity : o(2^n * n)

#define inc                                                                    \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> result;

    void calculating(vector<int>& nums, int i, vector<int> temp) {
        if (i >= nums.size()) {
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        calculating(nums, i + 1, temp);

        temp.pop_back();
        calculating(nums, i + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        inc;

        vector<int> temp;
        calculating(nums, 0, temp);

        for (auto it : st) {
            result.push_back(it);
        }

        return result;
    }
};
