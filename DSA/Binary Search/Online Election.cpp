/*  LeetCode link : https://leetcode.com/problems/online-election/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n)


#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class TopVotedCandidate {
public:
    vector<int> leadingPerson, times;
    int n;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        n = times.size();
        int currLead = -1;

        unordered_map<int, int> mp;
        for (int& candidate : persons) {
            mp[candidate]++;

            if (mp[candidate] >= mp[currLead])
                currLead = candidate;

            leadingPerson.push_back(currLead);
        }
    }

    int binaryS(int left, int target) {
        int right = n - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (times[mid] > target) {
                right = mid - 1;
            } else {
                result = mid;
                left = mid + 1;
            }
        }

        return result;
    }

    int q(int t) {
        inc();

        int idx = binaryS(0, t);
        return leadingPerson[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
