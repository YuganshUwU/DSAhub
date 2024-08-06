/*  Leetcode link : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
    Difficulty : Hard
*/

// Time Complexity : O(26*(V+E))
// Space Complexity : O(26*(V+E))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        inc();

        int n = colors.length();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        vector<vector<int>> colorVector(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                que.push(i);
                int idx = colors[i] - 'a';
                colorVector[i][idx]++;
            }
        }

        int result = INT_MIN;
        int nodes = 0;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            nodes++;

            int idx = colors[curr] - 'a';
            result = max(result, colorVector[curr][idx]);

            for (int& nextNode : adj[curr]) {
                for (int i = 0; i < 26; i++) {
                    colorVector[nextNode][i] = max(colorVector[nextNode][i], colorVector[curr][i] + (colors[nextNode] - 'a' == i));
                }
                indegree[nextNode]--;

                if (!indegree[nextNode])
                    que.push(nextNode);
            }
        }

        return nodes == n ? result : -1;
    }
};
