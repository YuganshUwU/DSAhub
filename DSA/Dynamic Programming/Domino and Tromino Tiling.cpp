/*  Leetcode link : https://leetcode.com/problems/domino-and-tromino-tiling/
    Difficulty : Medium
*/

// Approach 1 - Recursion TC : O(n!)  SC : O(1) excluding inbuilt stack space

#define inc()                                                                   \
ios_base::sync_with_stdio(0);                                                   \
cin.tie(0);                                                                     \
cout.tie(0)

class Solution {
public:
    int MOD + 1e9 + 7;

    int finding(int n){
        if(n == 1 || n == 2)
            return n;
        
        if(n == 3)
            return 5;
        
        return (2 * (finding(n - 1)) % MOD + (finding(n - 3)) % MOD ) % MOD;
    }

    int numTilings(int n) {
        inc();
        return finding(n);
    }
};

-------------------------------------------------------------------------------------------------------------------

// Approach 2 - Recursion + Memoization TC : O(n)  SC : O(n)

#define inc()                                                                   \
ios_base::sync_with_stdio(0);                                                   \
cin.tie(0);                                                                     \
cout.tie(0)

class Solution {
public:

    int dp[1001];
    int MOD = 1e9+ 7;

    int finding(int n){
        if(n == 1 || n == 2)
            return dp[n] = n;
        
        if(n == 3)
            return dp[n] = 5;

        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = (2 * (finding(n - 1)) % MOD + (finding(n - 3)) % MOD) % MOD;
    }

    int numTilings(int n) {
        inc();
        memset(dp, -1, sizeof(dp));
      
        return finding(n);
    }
};

----------------------------------------------------------------------------------------------------------------------

// Approach 3 - Dynamic Programming  TC : O(n) SC : O(n)

#define inc()                                                                  \
ios_base::sync_with_stdio(0);                                                  \
cin.tie(0);                                                                    \
cout.tie(0)

class Solution {
public:
    int numTilings(int n) {
        inc();
        
        int dp[1001];
        int MOD = 1e9 + 7;

        memset(dp, -1, sizeof(dp));

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4; i <= n; i++){
            dp[i] = (2 * (dp[i - 1]) % MOD + (dp[i - 3]) % MOD) % MOD; 
        }   

        return dp[n];
    }
};
