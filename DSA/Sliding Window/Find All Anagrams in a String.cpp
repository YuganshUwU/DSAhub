/*  LeetCode link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
    Difficulty : Medium
*/

// Time Complexity : O(26 * n) -> O(n)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        inc();

        int n = s.length();
        int m = p.length();

        if(n < m)
            return {};

        vector<int> sFreq(26, 0), pFreq(26, 0);

        for (int i = 0; i < m; i++) {
            sFreq[s[i] - 'a']++;
            pFreq[p[i] - 'a']++;
        }

        vector<int> result;

        int i = 0, j = m;

        while (j < n) {
            if (sFreq == pFreq)
                result.push_back(i);

            int idx = s[j++] - 'a';
            sFreq[idx]++;

            idx = s[i++] - 'a';
            sFreq[idx]--;
        }

        if (sFreq == pFreq)
            result.push_back(i);

        return result;
    }
};
