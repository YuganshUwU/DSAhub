/*  LeetCode link : https://leetcode.com/problems/prime-subtraction-operation/
    Difficulty : Medium
*/

// Time Complexity : O(n^2)
// Space Complexity : O(N)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void sieve(vector<bool>& prime) {
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < prime.size(); i++) {
            if (prime[i]) {
                for (int j = i * i; j < prime.size(); j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    bool isIncreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }

        return true;
    }

    int minPrime(int curr, vector<bool>& prime, int prev) {
        for (int i = curr - 1; i >= 2; i--) {
            if (prime[i] && curr - i > prev)
                return i;
        }

        return 0;
    }

    bool primeSubOperation(vector<int>& nums) {
        INC();

        vector<bool> prime(1001, true);
        sieve(prime);
        int n = nums.size();
        int prev = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (isIncreasing(nums))
                return true;

            int sub = minPrime(nums[i], prime, prev);
            nums[i] -= sub;
            prev = nums[i];
        }

        return isIncreasing(nums);
    }
};
