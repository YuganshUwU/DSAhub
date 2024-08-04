/*  Leetcode link : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
    Difficulty : Hard
*/

// Time Complexity : O(2^m * n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int result = INT_MIN;
    int m;

    void backtrack(int n, int idx, int total, vector<vector<int>>& requests, vector<int>& movements) {

        if (idx == m) {
            int totalZero = count(movements.begin(), movements.end(), 0);

            if (totalZero == n)
                result = max(result, total);

            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];

        movements[from]--;
        movements[to]++;
        backtrack(n, idx + 1, total + 1, requests, movements);

        movements[to]--;
        movements[from]++;
        backtrack(n, idx + 1, total, requests, movements);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        inc();

        m = requests.size();
        vector<int> movements(n, 0);
        backtrack(n, 0, 0, requests, movements);
        return result;
    }
};
