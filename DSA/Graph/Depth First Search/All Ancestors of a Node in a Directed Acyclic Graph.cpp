/*  Leetcode Link : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
    Difficulty : Medium\
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result) {
        
        for (auto ngbr : adj[currNode]) {
            if (result[ngbr].empty() || result[ngbr].back() != ancestor) {
                result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);
            }
        }
        
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        inc();

        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, result);
        }

        return result;
    }
};
