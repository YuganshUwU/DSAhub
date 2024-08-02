/*  Leetcode link : https://leetcode.com/problems/letter-case-permutation/
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
    vector<string> result;

    void backtrack(string& s, int idx) {
        if (idx == s.length()) {
            result.push_back(s);
            return;
        }

        char ch = s[idx];
        if (islower(ch)) {
            s[idx] = ch - 32;
            backtrack(s, idx + 1);
        } else if (isupper(ch)) {
            s[idx] = ch + 32;
            backtrack(s, idx + 1);
        }

        s[idx] = ch;
        backtrack(s, idx + 1);
    }

    vector<string> letterCasePermutation(string s) {
        inc();

        backtrack(s, 0);
        return result;
    }
};
