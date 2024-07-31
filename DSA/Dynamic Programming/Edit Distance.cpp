/*  Leetcode link : https://leetcode.com/problems/edit-distance/
    Difficulty : Medium
*/

// Recursion : TC : O(3^(n + m)) (TLE) , SC : O(max(m, n) 

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n, m;

    int finding(string& word1, string& word2, int i, int j) {
        if (i == n)
            return m - j;
        else if (j == m)
            return n - i;

        if (word1[i] == word2[j])
            return finding(word1, word2, i + 1, j + 1);

        int ins = 1 + finding(word1, word2, i, j + 1);
        int del = 1 + finding(word1, word2, i + 1, j);
        int rep = 1 + finding(word1, word2, i + 1, j + 1);

        return min({ins, del, rep});
    }

    int minDistance(string word1, string word2) {
        inc();

        n = word1.length();
        m = word2.length();

        return finding(word1, word2, 0, 0);
    }
};

------------------------------------------------------------------------------------------------------

  // Recursion + Memoization (Top-Down approach) : TC : O(m*n), SC : O(m*n + max(m,n))
  
#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int dp[501][501];
    int n, m;

    int finding(string& word1, string& word2, int i, int j) {
        if (i == n)
            return m - j;
        else if (j == m)
            return n - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = finding(word1, word2, i + 1, j + 1);

        int ins = 1 + finding(word1, word2, i, j + 1);
        int del = 1 + finding(word1, word2, i + 1, j);
        int rep = 1 + finding(word1, word2, i + 1, j + 1);

        return dp[i][j] = min({ins, del, rep});
    }

    int minDistance(string word1, string word2) {
        inc();

        memset(dp, -1, sizeof(dp));
        n = word1.length();
        m = word2.length();

        return finding(word1, word2, 0, 0);
    }
};

------------------------------------------------------------------------------------------------------

  // Recursion + Memoization (Bottom-Up approach) : TC : O(m*n), SC : O(m*n + max(m,n))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int dp[501][501];

    int finding(string& word1, string& word2, int m, int n) {
        if (!m || !n)
            return m + n;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (word1[m - 1] == word2[n - 1])
            return dp[m][n] = finding(word1, word2, m - 1, n - 1);

        int ins = 1 + finding(word1, word2, m, n - 1);
        int del = 1 + finding(word1, word2, m - 1, n);
        int rep = 1 + finding(word1, word2, m - 1, n - 1);

        return dp[m][n] = min({ins, del, rep});
    }

    int minDistance(string word1, string word2) {
        inc();
        memset(dp, -1, sizeof(dp));

        int m = word1.length();
        int n = word2.length();

        return finding(word1, word2, m, n);
    }
};

------------------------------------------------------------------------------------------------------

// Dynamic Programming Approach : TC : O(m*n), SC : O(m*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minDistance(string word1, string word2) {
        inc();

        int dp[501][501];
        memset(dp, -1, sizeof(dp));

        int m = word1.length();
        int n = word2.length();

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {

                if (!i || !j)
                    dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                        
            }
        }

        return dp[m][n];
    }
};
