/*  LeetCode link : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
    Difficulty : Medium
*/

// Time Complexity : O(n logn)
// Space Complexity : O(1)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int find(vector<int>& quantities, int val) {
        int count = 0;

        for (int& curr : quantities) {
            count += curr / val;

            if (curr % val)
                count++;
        }

        return count;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        INC();

        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int curr = find(quantities, mid);

            if (curr <= n) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
