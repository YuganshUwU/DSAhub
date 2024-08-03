/*  Leetcode Link : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void dfs(vector<int>& edges, int source, vector<int>& dist, vector<bool>& visited) {
        visited[source] = true;
        int node = edges[source];

        if (node != -1 && !visited[node]) {
            dist[node] = 1 + dist[source];
            dfs(edges, node, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        inc();

        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        vector<bool> vis1(n, false), vis2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, vis1);
        dfs(edges, node2, dist2, vis2);

        int result = -1;
        int maxVal = INT_MAX;

        for (int i = 0; i < n; i++) {
            int currMax = max(dist1[i], dist2[i]);
            
            if (maxVal > currMax) {
                maxVal = currMax;
                result = i;
            }
        }

        return result;
    }
};
