// Leetcode Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minimumDeletions(string s) {
        inc();

        string result = "";
        int times = 0;

        for (char& ch : s) {
            if (!result.empty() && result.back() == 'b' && ch == 'a') {
                result.pop_back();
                times++;
            } else
                result += ch;
        }

        return times;
    }
};
