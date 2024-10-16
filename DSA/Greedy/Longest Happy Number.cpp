/*  LeetCode link : https://leetcode.com/problems/longest-happy-string/
    Difficulty : Medium
*/

// Time Complexity : O(log₂3) -> O(1)
// Space Complexity : O(3) -> O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        inc();

        priority_queue<pair<int, char>> pq;
        string result = "";

        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        while (!pq.empty()) {
            int currFreq = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            int n = result.length();
            if (n >= 2 && result[n - 1] == currChar &&
                result[n - 2] == currChar) {
                if (pq.empty())
                    break;

                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextFreq--;

                if (nextFreq)
                    pq.push({nextFreq, nextChar});
            } else {
                currFreq--;
                result.push_back(currChar);
            }

            if (currFreq)
                pq.push({currFreq, currChar});
        }

        return result;
    }
};
