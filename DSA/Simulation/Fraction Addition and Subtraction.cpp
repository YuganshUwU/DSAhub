/*  LeetCode link : https://leetcode.com/problems/fraction-addition-and-subtraction/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(1)

#define inc()                                                                       \
    ios_base::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                     \
    cout.tie(0)

class Solution {
public:
    string fractionAddition(string expression) {
        inc();
        
        int n = expression.length();
        int num = 0, den = 1;
        int i = 0;

        while (i < n) {
            int currNum = 0, currDen = 1;
            bool negative = (expression[i] == '-');

            if (expression[i] == '+' || expression[i] == '-')
                i++;
            
            string numStr = "";
            while (i < n && isdigit(expression[i]))
                numStr += expression[i++];
            
            i++;
            currNum = stoi(numStr);
            if (negative)
                currNum = -currNum;
            
            string denStr = "";
            while (i < n && isdigit(expression[i]))
                denStr += expression[i++];
            
            currDen = stoi(denStr);

            num = num * currDen + currNum * den;
            den *= currDen;
        }

        int common = abs(__gcd(num, den));
        num /= common;
        den /= common;

        return to_string(num) + "/" + to_string(den);

    }
};
