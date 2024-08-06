/*  Leetcode link : https://leetcode.com/problems/satisfiability-of-equality-equations/
    Difficulty : Medium
*/

// Time Complexity : O(n* α(n)) , where α(x) = Inverse Ackermann function
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class DSU {
public:
    vector<int> rank, parent, size;

    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void UnionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    void UnionBySize(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (size[x_parent] >= size[y_parent]) {
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
    bool equationsPossible(vector<string>& equations) {
        inc();

        DSU dsu(26);

        for (string& str : equations) {
            if (str[1] == '=')
                dsu.UnionByRank(str[0] - 'a', str[3] - 'a');
        }

        for (string& str : equations) {
            if (str[1] == '!') {
                int x_parent = dsu.find(str[0] - 'a');
                int y_parent = dsu.find(str[3] - 'a');

                if (x_parent == y_parent)
                    return false;
            }
        }

        return true;
    }
};
