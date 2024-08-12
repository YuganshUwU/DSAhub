/*  Leetcode link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
    Difficulty : Easy
*/

// Time Complexity : O(n) -> n = maximum number of bits from start and goal
// Space Complexity : O(1)


class Solution {
public:
    int minBitFlips(int start, int goal) {
        return  __builtin_popcount(start^goal);
    }
};
