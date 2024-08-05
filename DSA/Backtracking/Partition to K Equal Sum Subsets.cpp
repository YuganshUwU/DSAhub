/*  Leetcode link : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
    Difficulty : Medium
*/

// Time Complexity : O(k * 2^n)
// Space Complexity : O(k)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;

    bool backtrack(int idx, vector<int>& nums, vector<int>& result, int k, int target) {

        if (idx >= n) {
            for (int i = 1; i < k; i++) {
                if (result[i] != result[i - 1])
                    return false;
            }

            return true;
        }

        int curr = nums[idx];

        for (int i = 0; i < k; i++) {
            if (curr + result[i] > target)
                continue;

            int j = i - 1;

            while (j >= 0) {
                if (result[i] == result[j])
                    break;
                j--;
            }

            if (j != -1)
                continue;

            result[i] += curr;
            if (backtrack(idx + 1, nums, result, k, target))
                return true;
            result[i] -= curr;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        inc();

        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k)
            return false;

        vector<int> result(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());

        return backtrack(0, nums, result, k, sum / k);
    }
};
