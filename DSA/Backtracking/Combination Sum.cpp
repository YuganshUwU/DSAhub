// Leetcode link : https://leetcode.com/problems/combination-sum/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, vector<int> temp, int idx) {
        if (!target) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || idx == candidates.size())
            return;

        temp.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], temp, idx);
        temp.pop_back();

        backtrack(candidates, target, temp, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        inc();

        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return result;
    }
};
