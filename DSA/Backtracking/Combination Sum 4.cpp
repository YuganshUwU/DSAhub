/*  Leetcode Link : https://leetcode.com/problems/combination-sum-iv/
    Difficulty : Medium
*/

// Recursion Approach
// Time Complexity : O(2^n)
// Space Complexity : O(max(n, target))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;

    int backtrack(int idx, vector<int>& nums, int target) {
        if (target == 0)
            return 1;

        if (target < 0 || idx >= n)
            return 0;

        int take = backtrack(0, nums, target - nums[idx]);
        int skip = backtrack(idx + 1, nums, target);

        return take + skip;
    }

    int combinationSum4(vector<int>& nums, int target) {
        inc();

        n = nums.size();
        return backtrack(0, nums, target);
    }
};

--------------------------------------------------------------------------------------------------------------------------

// Recursion + Memoization 
  
// Time Complexity : O(n*target)
// Space Complexity : O(n* target)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    int dp[201][1001];

    int backtrack(int idx, vector<int>& nums, int target) {
        if (target == 0)
            return 1;

        if (target < 0 || idx >= n)
            return 0;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int take = backtrack(0, nums, target - nums[idx]);
        int skip = backtrack(idx + 1, nums, target);

        return dp[idx][target] = take + skip;
    }

    int combinationSum4(vector<int>& nums, int target) {
        inc();

        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return backtrack(0, nums, target);
    }
};
