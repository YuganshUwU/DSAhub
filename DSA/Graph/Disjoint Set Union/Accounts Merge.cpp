/*  Leetcode link : https://leetcode.com/problems/accounts-merge/
    Difficulty : Medium
*/

// Time Complexity : O(n + n*k + nlog(k))
// Space Complexity :O(n)

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        inc();

        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> mails;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string curr = accounts[i][j];
                if (mails.find(curr) == mails.end())
                    mails[curr] = i;
                else
                    dsu.unionByRank(i, mails[curr]);
            }
        }

        vector<vector<string>> merged(n);

        for (auto& it : mails) {
            string curr = it.first;
            int node = dsu.find(it.second);
            merged[node].push_back(curr);
        }

        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (merged[i].size() == 0)
                continue;

            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto& it : merged[i]) {
                temp.push_back(it);
            }

            result.push_back(temp);
        }

        return result;
    }
};
