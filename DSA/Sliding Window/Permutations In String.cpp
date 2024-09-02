/*  Leetcode link : https://leetcode.com/problems/permutation-in-string/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        inc();

        int m = s1.length();
        int n = s2.length();

        if(m > n)
            return false;
        
        vector<int> s1Freq(26, 0), s2Freq(26, 0);

        for (int i = 0; i < m; i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        int matching = 0;

        for (int i = 0; i < 26; i++)
            matching += (s1Freq[i] == s2Freq[i]);

        int i = 0, j = m;

        while (j < n) {
            if (matching == 26)
                return true;

            int idx = s2[j++] - 'a';
            s2Freq[idx]++;

            if (s1Freq[idx] == s2Freq[idx])
                matching++;
            else if(s1Freq[idx] + 1 == s2Freq[idx])
                matching--;

            idx = s2[i++] - 'a';
            s2Freq[idx]--;

            if (s1Freq[idx] == s2Freq[idx])
                matching++;
            else if(s1Freq[idx] - 1 == s2Freq[idx])
                matching--;
        }

        return matching == 26;
    }
};
