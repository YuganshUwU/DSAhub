/*  LeetCode link : https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
    Difficulty : Medium
*/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)


#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    long long result = 0;

    int dfs(unordered_map<int, vector<int>>& adj, int source, int parent, int seats) {
        int curr = 1;

        for (int& node : adj[source]) {
            if (node != parent) {
                int value = dfs(adj, node, source, seats);
                curr += value;
                result += (int)ceil(value * 1.0 / seats);
            }
        }

        return curr;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        inc();

        unordered_map<int, vector<int>> adj;

        for (vector<int>& edge : roads) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj, 0, -1, seats);
        return result;
    }
};
