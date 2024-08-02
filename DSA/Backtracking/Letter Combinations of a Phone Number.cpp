/*  Leetcode Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Difficulty : Medium
*/

// Time Complexity : O(n * 4^n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<string> result;
    vector<string> dial = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int idx, string& digits, string& temp) {

        if (idx >= digits.size()) {
            result.push_back(temp);
            return;
        }

        int ind = digits[idx] - '0';
        string curr = dial[ind];

        for (int i = 0; i < curr.length(); i++) {

            temp.push_back(curr[i]);
            backtrack(idx + 1, digits, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        inc();

        if (!digits.size())
            return {};

        string temp = "";
        backtrack(0, digits, temp);

        return result;
    }
};
