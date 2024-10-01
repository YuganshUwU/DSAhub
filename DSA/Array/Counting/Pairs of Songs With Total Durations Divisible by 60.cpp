/*  LeetCode link : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
    Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(60) -> O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        inc();
        vector<long long> freq(60, 0);

        for (int& curr : time) {
            int rem = curr % 60;
            freq[rem]++;
        }

        long long result = 0;

        if (freq[0]) {
            long long x = freq[0];
            result += x * (x - 1) / 2;
        }

        for (int i = 1; i < 30; i++) {
            if (freq[i] && freq[60 - i])
                result += freq[i] * freq[60 - i];
        }

        if (freq[30]) {
            long long x = freq[30];
            result += x * (x - 1) / 2;
        }

        return result;
    }
};
