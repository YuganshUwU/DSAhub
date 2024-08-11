/*  Leetcode link : https://leetcode.com/problems/min-cost-to-connect-all-points/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class DSU {
public:
    vector<int> parent, rank, size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    void unionBySize(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
};

class Solution {
public:
    int kruskalAlgorithm(vector<vector<int>>& adj, int V) {
        inc();

        int sum = 0;
        DSU dsu(V);

        for (auto edge : adj) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            int x_parent = dsu.find(u);
            int y_parent = dsu.find(v);

            if (x_parent != y_parent) {
                dsu.unionByRank(u, v);
                sum += weight;
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int weight = abs(x1 - x2) + abs(y1 - y2);

                adj.push_back({i, j, weight});
            }
        }

        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(adj.begin(), adj.end(), lambda);

        return kruskalAlgorithm(adj, n);
    }
};
