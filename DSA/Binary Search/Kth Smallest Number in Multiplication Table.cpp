/*  Leetcode link : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
    Difficulty : Hard
*/

// Approach 1 - Max Heap 
// Time Complexity : O(n*m + n*mlog(k))
// Space Complexity : O(n*m + k)  MLE

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        inc();
        vector<int> nums;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                nums.push_back(i * j);
            }
        }

        priority_queue<int> pq;

        for (int& val : nums) {
            pq.push(val);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};

-----------------------------------------------------------------------------------------------------------------------

// Approach 2 - Binary Search
// Time Complexity : O(m*n*n)
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int smallerThan(int m, int n, int mid) {
        int curr = 0;

        for (int i = 1; i <= n; i++) {
            curr += min(m, mid / i);
        }

        return curr;
    }

    int findKthNumber(int m, int n, int k) {
        inc();

        int l = 1, r = m * n;
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int count = smallerThan(m, n, mid);

            if (count >= k) {
                result = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return result;
    }
};
