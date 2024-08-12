/*  Leetcode link : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
    Difficulty : Medium
*/

// Approach 1 

// Time Complexity : O(n) -> n = max number of bits from a,b or c
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        inc();

        int result = 0;

        while (a || b || c) {
            if (c & 1) {
                if (!(a & 1) && !(b & 1))
                    result++;
            } else {
                if (a & 1)
                    result++;

                if (b & 1)
                    result++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return result;
    }
};

------------------------------------------------------------------------------------------------------

// Approach 2 
// Complexities : Same as Appraoch 1

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        inc();

        int result = (a | b) ^ c;
        int temp = (a & b);
        int curr = result & temp;

        return __builtin_popcount(result) + __builtin_popcount(curr);
    }
};
