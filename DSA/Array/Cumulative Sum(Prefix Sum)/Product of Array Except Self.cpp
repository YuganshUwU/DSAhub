/*  Leetcode Link : https://leetcode.com/problems/product-of-array-except-self/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(1) except returned value

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        inc();
        int start = 1, end = 1;
        int n = nums.size();

        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            ans[i] *= start;
            start *= nums[i];
            ans[n - 1 - i] *= end;
            end *= nums[n - 1 - i];
        }

        return ans;
    }
};
