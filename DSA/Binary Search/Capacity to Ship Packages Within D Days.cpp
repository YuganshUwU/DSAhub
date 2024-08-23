/*  LeetCode link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
    Difficulty : Medium
*/

// Time Complexity : O(n * log(sum(weights) - max(weights)))
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int shippingDays(vector<int>& weights, int limit) {
        int days = 1, load = 0;

        for (int& wt : weights) {
            if (wt + load <= limit) {
                load += wt;
            } else {
                days++;
                load = wt;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        inc();

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int daysTaken = shippingDays(weights, mid);

            if (daysTaken <= days) {
                result = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return result;
    }
};
