/*  LeetCode link : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
    Difficulty : Medium
*/

// Time Coomplexity : O(N)
// Space Complexity : O(k)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        inc();

        int n = arr.size();
        vector<int> freq(k, 0);

        for (int& num : arr) {
            int rem = ((num % k) + k) % k;
            freq[rem]++;
        }

        if (freq[0] % 2)
            return false;

        for (int i = 1; i <= k / 2; i++)
            if (freq[i] != freq[k - i])
                return false;

        return true;
    }
};
