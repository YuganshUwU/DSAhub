/*  LeetCode link : https://leetcode.com/problems/count-numbers-with-unique-digits/
    Difficulty : Medium
*/

// Time Complexity : O(n) -> O(8) ->O(1)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        inc();

        if (!n)
            return 1;

        int result = 10;
        int curr = 9, dec = 9;

        while (n > 1 && dec) {
            curr *= dec;
            result += curr;
            
            dec--;
            n--;
        }

        return result;
    }
};
