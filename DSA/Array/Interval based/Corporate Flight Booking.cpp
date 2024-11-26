/*
  LeetCode link : https://leetcode.com/problems/corporate-flight-bookings/\
  Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(N)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        INC();

        vector<int> seats(n, 0);

        for (vector<int>& curr : bookings) {
            int first = curr[0] - 1;
            int last = curr[1];
            int currSeats = curr[2];

            seats[first] += currSeats;
            if(last < n) 
                seats[last] -= currSeats;
        }

        for(int i = 1; i < n; i++) {
            seats[i] += seats[i - 1];
        }

        return seats;
    }
};
