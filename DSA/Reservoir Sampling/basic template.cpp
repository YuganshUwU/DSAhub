// Time Complexity : O(n)
// Space Complexity : O(1) excluding copying vector

class Solution {
public:
    vector<int> vec;

    Solution(vector<int>& nums) : vec(nums) {
    }

    int Reservoir(int target) {
        int result = -1;
        int n = 0;

        for (int i = 0; i < vec.size(); i++) {
            n++;
            int current = rand() % n;

            if (current == n - 1)
                result = i;
        }

        return result;
    }
};
