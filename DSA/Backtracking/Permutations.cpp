/*  Leetcode Link : https://leetcode.com/problems/permutations/
    Difficulty : Medium
*/

// Approach 1 : Recursion + HashSet
// Time Complexity : O(n * n!)
// Space Complexity : O(n!)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    vector<vector<int>> result;
    unordered_set<int> st;

    void backtrack(vector<int>& nums, vector<int>& temp) {

        if (temp.size() >= n) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                backtrack(nums, temp);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        inc();

        n = nums.size();
        vector<int> temp;
        backtrack(nums, temp);

        return result;
    }
};

----------------------------------------------------------------------------------------------------------------------

// Approach 2 
// Time Complexity : O(n * n!)
// Space Complexity : O(n!)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> result;
    int n;

    void backtrack(int idx, vector<int>& nums) {

        if (idx >= n) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            backtrack(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        inc();

        n = nums.size();
        backtrack(0, nums);
        return result;
    }
};
