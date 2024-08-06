/*  Leetcode link : https://leetcode.com/problems/strange-printer/
    Difficulty : Hard
*/

// Approach 1 : Recursion + Memoization - TC : O(n^3)  SC : O(n^2)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    int dp[101][101];

    int finding(int l, int r, string& s) {
        if (l == r)
            return 1;

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int i = l + 1;

        while (i < n && s[i] == s[l])
            i++;

        if (i == n)
            return dp[l][r] = 1;

        int basic = 1 + finding(i, r, s);
        int greed = INT_MAX;

        for (int j = i; j < n; j++) {

            if (s[j] == s[l]) {
                int curr = finding(i, j - 1, s) + finding(j, r, s);
                greed = min(greed, curr);
            }
            
        }

        return dp[l][r] = min(basic, greed);
    }

    int strangePrinter(string s) {
        inc();

        memset(dp, -1, sizeof(dp));
        n = s.length();

        return finding(0, n - 1, s);
    }
};
