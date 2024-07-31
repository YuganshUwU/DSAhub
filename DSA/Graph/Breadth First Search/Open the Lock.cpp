/*  Leetcode link : https://leetcode.com/problems/open-the-lock/
    Difficulty : Medium
*/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    void theNeighbors(string& curr, queue<string>& que, unordered_set<string>& st) {

        for (int i = 0; i < 4; i++) {

            char ch = curr[i];

            char inc = ch == '9' ? '0' : ch + 1;
            char dec = ch == '0' ? '9' : ch - 1;

            curr[i] = inc;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        inc();

        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";
        queue<string> que;
        que.push(start);

        if (st.find(start) != st.end())
            return -1;

        int level = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                string curr = que.front();
                que.pop();

                if (target == curr)
                    return level;

                theNeighbors(curr, que, st);
            }

            level++;
        }

        return -1;
    }
};
