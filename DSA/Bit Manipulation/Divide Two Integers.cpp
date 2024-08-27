/*  LeetCode link : https://leetcode.com/problems/divide-two-integers/
    Difficulty : Medium
*/

// Time Complexity : O(log(dividend))
// Space Complexity : O(1)

#define inc()                                                                   \
    ios_base::sync_with_stdio(0);                                               \
    cin.tie(0);                                                                 \
    cout.tie(0)

class Solution {
public:
    int divide(int dividend, int divisor) {
        inc();
        
        if(dividend == divisor)
            return 1;
        
        bool sign = true;
        if(dividend >= 0 && divisor < 0)
            sign = false;
        
        if(dividend < 0 && divisor > 0)
            sign = false;
        
        long n = abs(dividend);
        long d = abs(divisor);

        long result = 0;

        while(n >= d){
            int power = 0;

            while(n >= (d << (power + 1)))
                power++;
            
            result += 1 << power;
            n -= (d << power);
        }

        if(result == (1 << 31)){
            if(sign)
                return INT_MAX;
            else
                return INT_MIN;
        }

        return sign ? result : -result;
    }
};
