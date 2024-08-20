/*  LeetCode link : https://leetcode.com/problems/stone-game-iv/
    Difficulty : Medium
*/

// Approach 1 : Recursion + Memoization
// Time Complexity : O(n * sqrt(n))    Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int dp[100001];

    bool finding(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;
        
        if(dp[n] != -1)
            return dp[n];

        double perfect = sqrt(n);

        if ((int)perfect * (int)perfect == n)
            return dp[n] = true;

        for (int i = 1; i * i <= n; i++) {
            bool result = finding(n - i * i);

            if(!result)
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        inc();

        memset(dp, -1, sizeof(dp));
        return finding(n);
    }
};


-----------------------------------------------------------------------------------------------------

// Approach 2 : Dynamic Programminng
// Time Complexity : O(n * sqrt(n))    Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool winnerSquareGame(int n) {
        inc();

        vector<int> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++){

                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
                
            }
        }

        return dp[n];
    }
};
