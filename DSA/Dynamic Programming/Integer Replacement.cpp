/*  LeetCode link : https://leetcode.com/problems/integer-replacement/
    Difficulty : Medium
*/

// Time Complexity : O(log n)
// Space Complexity : O(log n)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
  unordered_map<int, int> dp;

    uint finding(uint n) {
        if (n == 1)
            return 0;

        if(dp.find(n) != dp.end())
            return dp[n];
          
        uint even = INT_MAX, plusOne = INT_MAX, minusOne = INT_MAX;

        if (n % 2 == 0)
            even = 1 + finding(n / 2);
        else {
            plusOne = 1 + finding(n + 1);
            minusOne = 1 + finding(n - 1);
        }

        return dp[n] = min({even, plusOne, minusOne});
    }

    int integerReplacement(int n) {
        INC();

        return finding(n);
    }
};
