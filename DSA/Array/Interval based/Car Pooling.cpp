/*
  LeetCode link : https://leetcode.com/problems/car-pooling/
  Difficulty : Medium
*/

// Using a new Trick here that I found just now for such type of questions :

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        INC();

        vector<int> passengers(1001, 0);

        for (vector<int>& trip : trips) {
            int currPass = trip[0];
            int from = trip[1];
            int to = trip[2];

            passengers[from] += currPass;
            passengers[to] -= currPass;
        }

        int count = 0;
        for (int i = 0; i < 1001; i++) {
            count += passengers[i];
            if (count > capacity)
                return false;
        }

        return true;
    }
};
