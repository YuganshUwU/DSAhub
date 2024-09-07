/*  LeetCode link : https://leetcode.com/problems/number-of-music-playlists/
    Difficulty : Hard
*/

// Time Complexity : O(goal * n)
// Space Complexity : O(goal * n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:

    int n, goal, k;
    int MOD = 1e9 + 7;
    int dp[101][101];

    long finding(int allSongs, int uniqueSongs) {

        if (allSongs == goal) {
            if (uniqueSongs == n)
                return 1;

            return 0;
        }

        if(dp[allSongs][uniqueSongs] != -1) 
            return dp[allSongs][uniqueSongs];

        long result = 0;

        if (uniqueSongs < n)
            result = (result + (n - uniqueSongs) * finding(allSongs + 1, uniqueSongs + 1)) % MOD;
        if (uniqueSongs > k)
            result = (result + (uniqueSongs - k) * finding(allSongs + 1, uniqueSongs)) % MOD;

        return dp[allSongs][uniqueSongs] = result % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        inc();

        memset(dp, -1, sizeof(dp));

        this->n = n;
        this->goal = goal;
        this->k = k;

        return finding(0, 0);
    }
};
