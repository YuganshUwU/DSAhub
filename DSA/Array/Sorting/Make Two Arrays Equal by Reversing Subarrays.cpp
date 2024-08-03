/*  Leetcode link : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
    Difficulty : Easy
*/

// Time Complexity : O(n) where n = 1001
// Space Complexity : O(n) where n = 1001

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        inc();

        vector<int> count(1001, 0);
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            count[arr[i]]--;
            count[target[i]]++;
        }

        for (int& val : count)
            if (val != 0)
                return false;
        
        return true;
    }
};
