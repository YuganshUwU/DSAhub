/*  Leetcode link : https://leetcode.com/problems/partition-equal-subset-sum/description/
    Difficulty : Medium
*/

// Approach 1 : Recursion -  TE : O(2^n) TLE , SC : O(n)

class Solution {
public:
    int n;

    bool backtrack(int idx, vector<int>& nums, vector<int>& result, int target) {

        if (idx >= n)
            return result[0] == result[1];

        int curr = nums[idx];

        for (int i = 0; i < 2; i++) {
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
            if (backtrack(idx + 1, nums, result, target))
                return true;
            result[i] -= curr;
        }

        return false;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());

        if (nums[0] > sum / 2)
            return false;

        vector<int> result(2, 0);
        return backtrack(0, nums, result, sum / 2);
    }
};

-----------------------------------------------------------------------------------------------------------------------

// Approach 2 : Recursion + Memoization - Top Down    TC : O(m*n)  SC : O(m*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool backtrack(int idx, vector<int>& nums, int target) {
        if (idx == n || target < 0)
            return false;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        if (!target)
            return dp[idx][target] = true;

        return dp[idx][target] = backtrack(idx + 1, nums, target - nums[idx]) || backtrack(idx + 1, nums, target);
    }

    bool canPartition(vector<int>& nums) {
        inc();

        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        dp.resize(n, vector<int>(sum / 2 + 1, -1));
        return backtrack(0, nums, sum / 2);
    }
};

-----------------------------------------------------------------------------------------------------------------------

// Approach 3 : Recursion + Memoization - Bottom Up   TC :O(m*n)  SC:O(m*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> dp;

    bool backtrack(int n, vector<int>& nums, int target) {
        if (n == -1 || target < 0)
            return false;

        if (dp[n][target] != -1)
            return dp[n][target];

        if (!target)
            return dp[n][target] = true;

        return dp[n][target] = backtrack(n - 1, nums, target - nums[n]) || backtrack(n - 1, nums, target);
    }

    bool canPartition(vector<int>& nums) {
        inc();

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        dp.resize(n, vector<int>(sum / 2 + 1, -1));
        return backtrack(n - 1, nums, sum / 2);
    }
};

-----------------------------------------------------------------------------------------------------------------------

// Approach 4 : Bottom Up Dynamic Programming -   TC : O(m*n)  SC : O(m*n)

#define inc()\
ios_base::sync_with_stdio(0);\
cin.tie(0);\
cout.tie(0)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        inc();
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++) {
                if(j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][target];
    }
};
