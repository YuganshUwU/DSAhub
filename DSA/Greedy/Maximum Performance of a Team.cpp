/*  Leetcode link : https://leetcode.com/problems/maximum-performance-of-a-team/\
    Difficulty : Hard
*/

// Time Complexity : O(nlogn)
// Space Complexity : O(k) excluding the engg vector

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int MOD = 1e9 + 7;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        inc();
        vector<pair<int, int>> engg;

        for (int i = 0; i < n; i++) {
            int eff = efficiency[i];
            int spd = speed[i];

            engg.push_back({eff, spd});
        }

        sort(engg.begin(), engg.end(), greater<pair<int, int>>());

        long long result = 0;
        long long spd = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (pair<int, int>& curr : engg) {
            if (pq.size() == k) {
                spd -= pq.top();
                pq.pop();
            }

            spd += curr.second;
            pq.push(curr.second);

            result = max(result, (curr.first * spd));
        }

        return result % MOD;
    }
};
