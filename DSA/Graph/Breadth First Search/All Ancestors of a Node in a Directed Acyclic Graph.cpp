/*  Leetcode Link : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        inc();

        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> que;
            vector<int> temp;

            que.push(i);
            visited[i] = true;

            while (!que.empty()) {
                int curr = que.front();
                que.pop();

                for (int& v : adj[curr]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        temp.push_back(v);
                        que.push(v);
                    }
                }
            }
                
            sort(temp.begin(), temp.end());
            result.push_back(temp);
            
        }

        return result;
    }
};
