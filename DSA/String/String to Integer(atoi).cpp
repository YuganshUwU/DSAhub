/*  LeetCode link : https://leetcode.com/problems/string-to-integer-atoi/
    Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int myAtoi(string s) {
        inc();

        int n = s.length();
        long long result = 0;
        bool begin = true;

        int idx = 0;
        while (idx < n && s[idx] == ' ')
            idx++;

        int start = idx;
        bool neg = false;

        while (idx < n) {
            if (isalpha(s[idx]))
                break;
            else if (s[idx] == ' ' && !begin)
                break;
            else if ((s[idx] == '-' || s[idx] == '+') && !begin)
                break;
            else if (s[idx] == '.')
                break;
            else {
                if (s[idx] == '-' || s[idx] == '+'){
                    if(s[idx] == '-')
                        neg = true;

                    begin = false;
                } else {
                    
                    result = result * 10 + (s[idx] - '0');
                    if(result > INT_MAX)
                        return neg ? INT_MIN : INT_MAX;

                    if (start == idx)
                        begin = false;
                }
            }

            idx++;
        }

        return neg ? -result : result;
    }
};
