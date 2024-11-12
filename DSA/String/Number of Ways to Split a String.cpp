/*  LeetCode link : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
    Difficulty : Medium
*/

// Time Complexity : O(26 * n) -> O(n)
// Space Complexity : O(26 + 26) -> O(1)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int numSplits(string s) {
        INC();

        int n = s.length();
        vector<int> freq(26, 0);

        for (char& ch : s)
            freq[ch - 'a']++;

        vector<int> cumFreq(26, 0);
        int result = 0;

        for (int i = 0; i < n - 1; i++) {
            char currCh = s[i];
            cumFreq[currCh - 'a']++;
            freq[currCh - 'a']--;

            int countLeft = 26 - count(cumFreq.begin(), cumFreq.end(), 0);
            int countRight = 26 - count(freq.begin(), freq.end(), 0);

            if (countLeft == countRight)
                result++;
        }

        return result;
    }
};
