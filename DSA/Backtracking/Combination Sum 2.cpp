/*  Leetcode link : https://leetcode.com/problems/combination-sum-ii/
    Difficulty : Medium
*/

// Time Complexity : O(2^n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int idx, vector<int>& candidates, vector<int>& temp, int target) {
        if (!target) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (candidates[i] > target)
                break;

            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            temp.push_back(candidates[i]);
            backtrack(i + 1, candidates, temp, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        inc();

        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, temp, target);
        return result;
    }
};
