/* Leetcode link : https://leetcode.com/problems/cheapest-flights-within-k-stops/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        inc();
        vector<int> distance(n, INT_MAX);

        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            mp[u].push_back({v, cost});
        }

        queue<pair<int, int>> q;
        int step = 0;
      
        q.push({src, 0});
        distance[src] = 0;
      
      while (!q.empty() && step <= k) {
            int N = q.size();
      
            while (N--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                for (auto it : mp[u]) {
                    int v = it.first;
                    int cost = it.second;

                    if (distance[v] > d + cost) {
                        distance[v] = d + cost;
                        q.push({v, d + cost});
                    }
                }
            }
            
        step++;
        }
        
      return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
