/*  LeetCode link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        inc();

        unordered_map<int, int> mp;
        int mask = 0;

        mp[mask] = -1;
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                mask = (mask ^ 1);
            } else if (s[i] == 'e') {
                mask = mask ^ (1 << 1);
            } else if (s[i] == 'i') {
                mask = mask ^ (1 << 2);
            } else if (s[i] == 'o') {
                mask = mask ^ (1 << 3);
            } else if (s[i] == 'u')
                mask = mask ^ (1 << 4);

            if (mp.find(mask) != mp.end())
                result = max(result, i - mp[mask]);
            else
                mp[mask] = i;
        }

        return result;
    }
};
