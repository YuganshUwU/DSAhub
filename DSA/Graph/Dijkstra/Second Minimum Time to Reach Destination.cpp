/*  Leetcode Link : https://leetcode.com/problems/second-minimum-time-to-reach-destination/
    Difficulty : Hard
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

typedef pair<int, int> p;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        inc();

        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> firstMin(n + 1, INT_MAX);
        vector<int> secondMin(n + 1, INT_MAX);

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 1});
        firstMin[1] = 0;

        while (!pq.empty()) {
            int timePassed = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n && secondMin[n] != INT_MAX)
                return secondMin[n];

            int div = timePassed / change;
            if (div % 2) {
                timePassed = (div + 1) * change;
            }

            for (auto& nextNode : adj[node]) {
                int currTime = timePassed + time;

                if (firstMin[nextNode] > currTime) {
                    secondMin[nextNode] = firstMin[nextNode];
                    firstMin[nextNode] = currTime;
                    pq.push({currTime, nextNode});
                } else if (secondMin[nextNode] > currTime && firstMin[nextNode] != currTime) {
                    secondMin[nextNode] = currTime;
                    pq.push({currTime, nextNode});
                }
            }
        }

        return -1;
    }
};
