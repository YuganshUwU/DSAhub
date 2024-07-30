// Leetcode Link               : https://leetcode.com/problems/network-delay-time/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

typedef pair<int, int> p;

class Solution {
public:
    int Dijkstra(unordered_map<int, vector<p>>& adj, int& n, int& k) {

        vector<int> timeTaken(n + 1, INT_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, k});
        timeTaken[k] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for (auto& node : adj[curr]) {
                int nextNode = node.first;
                int nextTime = node.second;

                if (timeTaken[nextNode] > time + nextTime) {
                    timeTaken[nextNode] = time + nextTime;
                    pq.push({time + nextTime, nextNode});
                }
            }

        }

        int result = *max_element(timeTaken.begin() + 1, timeTaken.end());
        return result == INT_MAX ? -1 : result;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        inc();

        unordered_map<int, vector<p>> adj;
        
        for (vector<int>& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int tm = edge[2];

            adj[u].push_back({v, tm});
        }

        return Dijkstra(adj, n, k);
    }
};
