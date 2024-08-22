/*  LeetCode link : https://leetcode.com/problems/koko-eating-bananas/
    Difficulty : Medium
*/

// Time Complexity : O(log(max(piles)))
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long eating(vector<int>& piles, int val) {
        long sum = 0;

        for (int& curr : piles) {
            sum += (curr / val);

            if (curr % val != 0)
                sum++;
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        inc();

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long rate = eating(piles, mid);

            if (rate <= h) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
