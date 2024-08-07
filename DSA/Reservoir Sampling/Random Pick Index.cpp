/*  Leetcode link : https://leetcode.com/problems/random-pick-index/
    Difficulty : Medium
*/

// Approach 1 : Reservoir sampling

// Time Complexity : O(n)
// Space Complexity : O(1) excluding copying vector

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> vec;

    Solution(vector<int>& nums) {
        inc();
        vec = nums;
    }

    int pick(int target) {
        int result = -1;
        int n = 0;

        for (int i = 0; i < vec.size(); i++) {

            if (vec[i] != target)
                continue;

            n++;
            int current = rand() % n;

            if (current == n - 1)
                result = i;
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


----------------------------------------------------------------------------------------------------------------------------

// Approach 2 : Smart Approach

// Time complexity : O(1)
// Space Complexity :O(1) excluding copying vector

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> vec;

    Solution(vector<int>& nums): vec(nums){
        inc();
    }

    int pick(int target) {
        int random = rand() % vec.size();
        if (vec[random] == target)
            return random;
        return pick(target);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
