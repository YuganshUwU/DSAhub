/*  Leetcode link : https://leetcode.com/problems/combination-sum-iii/
    Difficulty : Medium
*/

// Time Complexity : O(9*2^k)
// Space Complexity : O(k)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int& k, int n, vector<int>& temp, int start) {
        if (temp.size() == k && !n) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < 10; i++) {

            if (i > n)
                break;

            temp.push_back(i);
            backtrack(k, n - i, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        inc();

        if (n > 55)
            return {};

        vector<int> temp;
        backtrack(k, n, temp, 1);

        return result;
    }
};
