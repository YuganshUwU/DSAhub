/*  Leetcode link : https://leetcode.com/problems/permutations-ii/
    Difficulty : Medium
*/

// Time Complexity : O(n * n!)
// Space Complexity : O(n!)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;

    void backtrack(int idx, vector<int>& nums, int& n) {

        if (idx >= n) {
            st.insert(nums);
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            backtrack(idx + 1, nums, n);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        inc();

        int n = nums.size();
        backtrack(0, nums, n);

        for (vector<int>& vec : st)
            result.push_back(vec);

        return result;
    }
};
