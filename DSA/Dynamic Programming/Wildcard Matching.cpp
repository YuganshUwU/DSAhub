/*  Leetcode link : https://leetcode.com/problems/wildcard-matching/
    Difficulty : Hard
*/

// Approach 1 - Recursion
// Time Complexity : O(2^(m*n))  TLE
// Space Complexity :O(1) excluding memory stack space

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    bool finding(string& s, string& p, int i, int j) {

        if (i == m && j == n)
            return true;

        if (i == m && j < n) {
            for (int idx = j; idx < n; idx++) {
                if (p[idx] != '*')
                    return false;
            }
            return true;
        }

        if (i < m && j == n)
            return false;

        if (s[i] == p[j] || p[j] == '?')
            return finding(s, p, i + 1, j + 1);

        if (p[j] == '*')
            return finding(s, p, i, j + 1) || finding(s, p, i + 1, j);

        return false;
    }

    bool isMatch(string s, string p) {
        inc();

        m = s.length();
        n = p.length();

        return finding(s, p, 0, 0);
    }
};

----------------------------------------------------------------------------------------------------------------

// Approach 2 - Recursion + Memoization
// Time Complexity : O(m * n)
// Space Complexity : O(m + n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int m, n;
    int dp[2001][2001];

    bool finding(string& s, string& p, int i, int j) {

        if (i == m && j == n)
            return true;

        if (i == m && j < n) {
            for (int idx = j; idx < n; idx++) {
                if (p[idx] != '*')
                    return false;
            }
            return true;
        }

        if (i < m && j == n)
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = finding(s, p, i + 1, j + 1);

        if (p[j] == '*')
            return dp[i][j] = finding(s, p, i, j + 1) || finding(s, p, i + 1, j);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        inc();

        m = s.length();
        n = p.length();

        memset(dp, -1, sizeof(dp));

        return finding(s, p, 0, 0);
    }
};

----------------------------------------------------------------------------------------------------------------

// Approach 3 - Recursion + Memoization : Bottom Up Approach
// Time Complexity : O(m*n)
// Space Complexity : O(m + n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int dp[2001][2001];

    bool finding(string& s, string& p, int m, int n) {

        if (m == 0 && n == 0)
            return true;

        if (m == 0 && n > 0) {
            for (int idx = 1; idx <= n; idx++) {
                if (p[idx - 1] != '*')
                    return false;
            }
            return true;
        }

        if (m > 0 && n == 0)
            return false;

        if(dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == p[n - 1] || p[n - 1] == '?')
            return dp[m][n] = finding(s, p, m - 1, n - 1);

        if (p[n - 1] == '*')
            return dp[m][n] = finding(s, p, m, n - 1) || finding(s, p, m - 1, n);

        return dp[m][n] = false;
    }

    bool isMatch(string s, string p) {
        inc();

        int m = s.length();
        int n = p.length();

        memset(dp, -1, sizeof(dp));

        return finding(s, p, m, n);
    }
};

----------------------------------------------------------------------------------------------------------------

// Approach 4 - Dynamic Programming 
// Time Complexity : O(m * n)
// Space Complexity : O(m + n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool isMatch(string s, string p) {
        inc();

        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= m; i++) {
            dp[i][0] = false;
        }

        for (int i = 1; i <= n; i++) {
            bool flag = true;

            for (int idx = 1; idx <= i; idx++)
                if (p[idx - 1] != '*') {
                    flag = false;
                    break;
                }

            dp[0][i] = flag;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            }
        }

        return dp[m][n];
    }
};
