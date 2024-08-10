/*  Leetcode link : https://leetcode.com/problems/multiply-strings/
    Difficulty : Medium
*/

// Time Complexity : O(m*n)
// Space Complexity : O(1) excluding returned string

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    string multiply(string num1, string num2) {
        inc();

        int m = num1.length();
        int n = num2.length();

        string result(m + n, '0');

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int curr = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = curr % 10 + '0';
                result[i + j] += curr / 10;
            }
        }

        for (int i = 0; i < m + n; i++) {
            if (result[i] != '0')
                return result.substr(i);
        }

        return "0";
    }
};
