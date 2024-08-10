/*  Leetcode link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
    Difficulty : Medium
*/

// Time Complexity : O(5* n) -> O(n)
// Space Complexity : O(5) -> O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int maxVowels(string s, int k) {
        inc();

        int n = s.length();
        string vowels = "aeiou";

        int i = 0, j = k - 1;
        int count = 0;
        int maxCount = INT_MIN;

        for (int idx = 0; idx <= j; idx++) {
            if (vowels.find(s[idx]) != string::npos) {
                count++;
                maxCount = max(maxCount, count);
            }
        }

        while (j < n) {
            if (vowels.find(s[i]) != string::npos)
                count--;
            i++;

            j++;
            if (vowels.find(s[j]) != string::npos)
                count++;

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
