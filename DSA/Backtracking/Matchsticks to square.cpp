/*  Leetcode link : https://leetcode.com/problems/matchsticks-to-square/
    Difficulty : Medium
*/

// Time Complexity : O(4 * 2^n) 
// Space Complexity :O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;

    bool backtrack(int idx, vector<int>& matchsticks, vector<int> sides, int target) {
        if (idx == n) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        int curr = matchsticks[idx];

        for (int i = 0; i < 4; i++) {
            if (curr + sides[i] > target)
                continue;

            int j = i - 1;
            while (j >= 0) {
                if (sides[i] == sides[j])
                    break;
                j--;
            }

            if (j != -1)
                continue;

            sides[i] += curr;
            if (backtrack(idx + 1, matchsticks, sides, target))
                return true;

            sides[i] -= curr;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        inc();

        n = matchsticks.size();

        if (n < 4)
            return false;

        vector<int> sides(4, 0);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        if (matchsticks[0] > sum / 4)
            return false;

        return backtrack(0, matchsticks, sides, sum / 4);
    }
};
