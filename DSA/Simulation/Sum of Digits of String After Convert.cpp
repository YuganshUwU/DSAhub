/*  LeetCode link : https://leetcode.com/problems/sum-of-digits-of-string-afnter-convert/
    Difficulty : Easy
*/

// Time Complexity : O(n) + O(k * len(num))
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int getLucky(string s, int k) {
        inc();

        int num = 0;
        string value = "";

        for (char& ch : s) {
            value += to_string(ch - 'a' + 1);
        }

        for (char& ch : value)
            num += (ch - '0');

        while (k - 1) {
            int curr = num;
            int res = 0;

            while (curr) {
                res += curr % 10;
                curr /= 10;
            }

            num = res;
            k--;
        }

        return num;
    }
};
