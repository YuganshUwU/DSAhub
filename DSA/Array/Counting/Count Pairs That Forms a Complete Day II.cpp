/*  LeetCode link : https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/
    Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(24) -> O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        inc();

        int n = hours.size();
        vector<long long> freq(24, 0);

        for (int& hr : hours) {
            int rem = hr % 24;
            freq[rem]++;
        }

        long long result = 0;

        if (freq[0]) {
            long long x = freq[0];
            result += x * (x - 1) / 2;
        }

        for (int i = 1; i < 12; i++) {
            if (freq[i] && freq[24 - i])
                result += (freq[i] * freq[24 - i]);
        }

        if (freq[12]) {
            long long x = freq[12];
            result += x * (x - 1) / 2;
        }

        return result;
    }
};
