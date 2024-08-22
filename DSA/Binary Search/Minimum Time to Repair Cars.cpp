/*  LeetCode link : https://leetcode.com/problems/minimum-time-to-repair-cars/
    Difficulty : Medium
*/

// Time Complexity : O(n * log(1e14))
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long repairing(vector<int>& ranks, long long val) {
        long long fixedCars = 0;

        for (int& curr : ranks) {
            fixedCars += sqrt(val / curr);
        }

        return fixedCars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        inc();

        long long result = 0;
        long long left = 1;
        long long right = 1e14;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long fixedCars = repairing(ranks, mid);

            if (fixedCars >= cars) {
                result = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return result;
    }
};
