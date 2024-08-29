/*  LeetCode link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    Difficulty : Medium
*/

// Time Complexity : O(n * α(n))
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
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
    int removeStones(vector<vector<int>>& stones) {
        inc();

        int n = stones.size();
        int row = 0, col = 0;

        for (vector<int>& coord : stones) {
            row = max(row, coord[0]);
            col = max(col, coord[1]);
        }

        DSU dsu(row + col + 1);
        unordered_map<int, int> mp;

        for (vector<int>& stone : stones) {
            int u = stone[0];
            int v = stone[1] + row + 1;

            dsu.unionBySize(u, v);
            mp[u]++;
            mp[v]++;
        }

        int result = 0;

        for (auto& curr : mp) {
            if (dsu.find(curr.first) == curr.first)
                result++;
        }

        return n - result;
    }
};
