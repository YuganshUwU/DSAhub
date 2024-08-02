/*  Leetcode Link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
    Difficulty : Medium
*/

// Approach 1 : Using a vector 2 times than the input.

// Time Complexity : O(2*n)
// Space Complexity :O(2*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        inc();

        int n = nums.size();
        vector<int> vec(2 * n, 0);

        for (int i = 0; i < 2 * n; i++) {
            vec[i] = nums[i % n];
        }

        int i = 0;
        int j = 0;

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int currOnes = 0;
        int result = 0;

        while (j < 2 * n) {
            if (vec[j])
                currOnes++;

            if (j - i + 1 > totalOnes) {
                currOnes -= vec[i];
                i++;
            }

            result = max(result, currOnes);
            j++;
        }

        return totalOnes - result;
    }
};

----------------------------------------------------------------------------------------------------------------

// Approach 2 : Using constant memory

// Time Complexity : O(2 * n)
// Space Complexity : O(1)

  #define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        inc();

        int n = nums.size();

        int i = 0;
        int j = 0;

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int currOnes = 0;
        int result = 0;

        while (j < 2 * n) {
            if (nums[j % n])
                currOnes++;

            if (j - i + 1 > totalOnes) {
                currOnes -= nums[i % n];
                i++;
            }

            result = max(result, currOnes);
            j++;
        }

        return totalOnes - result;
    }
};
