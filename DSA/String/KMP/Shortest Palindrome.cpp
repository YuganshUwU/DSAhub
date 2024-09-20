/*  LeetCode link : https://leetcode.com/problems/shortest-palindrome/
    Difficulty : Hard
*/

// Time Complexity : O(n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void computeLPS(string& pattern, vector<int>& lps) {
        int n = pattern.length();
        int i = 1, len = 0;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        inc();

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "-" + rev;
        vector<int> LPS(temp.length(), 0);

        computeLPS(temp, LPS);
        int faulty = LPS.back();

        return rev.substr(0, s.length() - faulty) + s;
    }
};
