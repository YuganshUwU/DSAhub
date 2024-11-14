/*  LeetCode link : https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
    Difficulty : Medium
*/

// Time Complexity : O(n log(sum(nums))
// Space Complexity : O(1)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long find(vector<int>& candies, long long val) {
        long long count = 0;

        for (int i = 0; i < candies.size(); i++) {
            count += (candies[i] / val);
        }

        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        INC();

        long long sum = accumulate(candies.begin(), candies.end(), 0ll);
        long long l = 1, r = sum;
        int result = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long curr = find(candies, mid);

            if (curr >= k) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
