/*  LeetCode link : https://leetcode.com/problems/extra-characters-in-a-string/
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
    int n;
    int dp[51];

    int finding(int idx, string s, unordered_set<string>& st) {
        if (idx >= n)
            return 0;

        string currStr = "";
        int result = n;

        if(dp[idx] != -1)
            return dp[idx];

        for (int i = idx; i < n; i++) {
            currStr.push_back(s[i]);
            int currExtra = st.find(currStr) == st.end() ? currStr.length() : 0;
            int nextExtras = finding(i + 1, s, st);

            result = min(result, currExtra + nextExtras);
        }

        return dp[idx] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        inc();

        memset(dp, -1, sizeof(dp));

        n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        return finding(0, s, st);
    }
};
