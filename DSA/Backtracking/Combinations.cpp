/*  Leetcode Link : https://leetcode.com/problems/combinations/
    Difficulty : Medium
*/

// Time Complexity : O(ⁿCₖ)
// Space Complexity : O(2^(max(k, n))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;
    int N;

    void backtrack(int idx, vector<int>& nums, vector<int>& temp, int& k) {

        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < N; i++) {
            temp.push_back(nums[i]);
            backtrack(i + 1, nums, temp, k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        inc();

        N = n;
        vector<int> nums;

        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<int> temp;
        backtrack(0, nums, temp, k);

        return result;
    }
};
