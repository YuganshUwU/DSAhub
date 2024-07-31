/*  Leetcode Link : https://leetcode.com/problems/find-the-safest-path-in-a-grid/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool check(vector<vector<int>>& manhattenDistt, int mid_sf) {
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        que.push({0, 0});
        visited[0][0] = true;

        if(manhattenDistt[0][0] < mid_sf)
            return false;

        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();

            if (curr_i == n - 1 && curr_j == n - 1)
                return true;

            for (auto &dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                    if (manhattenDistt[new_i][new_j] < mid_sf)
                        continue;

                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        inc();

        n = grid.size();

        vector<vector<int>> manhattenDistt(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();

                manhattenDistt[curr_i][curr_j] = level;

                for (auto &dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if (new_i < 0 ||new_i > n - 1 ||new_j < 0 ||new_j > n - 1 ||visited[new_i][new_j])
                        continue;

                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            level++;
        }

        int left = 0, right = 400;
        int result = 0;

        while (left <= right) {
            int mid_sf = left + (right - left) / 2;

            if (check(manhattenDistt, mid_sf)) {
                result = mid_sf;
                left = mid_sf + 1;
            } else {
                right = mid_sf - 1;
            }
        }

        return result;
    }
};
