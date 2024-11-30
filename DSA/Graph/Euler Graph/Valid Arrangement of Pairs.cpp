/* LeetCode link : https://leetcode.com/problems/valid-arrangement-of-pairs/
    Difficulty : Hard
*/

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<int>& path) {

        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(adj, v, path);
        }

        path.push_back(u);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        INC();

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        for (vector<int>& pair : pairs) {
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        int start = pairs[1][0];

        for (auto& it : adj) {
            int curr = it.first;
            if (outdegree[curr] - indegree[curr] == 1) {
                start = curr;
                break;
            }
        }

        vector<int> eulerPath;
        dfs(adj, start, eulerPath);

        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;

        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};
