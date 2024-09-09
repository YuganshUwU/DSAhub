/*  LeetCode link : https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
    Difficulty : Hard
*/

// Time Complexity : O(m * (1 << n))
// Space Complexity : O(n * (1 << m))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:

    int m;
    int MOD = 1e9 + 7;
    int dp[41][(1 << 10) + 1];

    int finding(unordered_map<int, vector<int>>& persons, int idx, int mask) {

        if (mask == (1 << m) - 1)
            return 1;

        if (idx >= 40)
            return 0;

        if(dp[idx][mask] != -1)
            return dp[idx][mask];

        int result = finding(persons, idx + 1, mask);

        for (int i = 0; i < persons[idx].size(); i++) {
            int j = persons[idx][i];

            if (mask & (1 << j))
                continue;

            int newMask = mask | (1 << j);
            result = (result + finding(persons, idx + 1, newMask)) % MOD;
        }

        return dp[idx][mask] = result;
    }

    int numberWays(vector<vector<int>>& hats) {
        inc();

        memset(dp, -1, sizeof(dp));
        m = hats.size();
        unordered_map<int, vector<int>> persons;

        for (int i = 0; i < m; i++) {
            for (int& curr : hats[i])
                persons[curr - 1].push_back(i);
        }

        return finding(persons, 0, 0);
    }
};
