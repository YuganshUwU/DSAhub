/*  Leetcode link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
    Difficulty : Medium
*/

// Approach 1 - Brute Force 
//Time Complexity : O(n*n log(n*n))   Space Complexity : O(n*n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        inc();

        int n = matrix.size();
        vector<int> result(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                result[i * n + j] = matrix[i][j];
        }

        sort(result.begin(), result.end());
        return result[k - 1];
    }
};

-----------------------------------------------------------------------------------------------------------

// Approach 2 - Using Priority Queue
// Time Complexity : O(n*n log(k))    Space Complexity : O(k)
  
#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        inc();

        int n = matrix.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);

                if (pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};

-----------------------------------------------------------------------------------------------------------

// Approach 3 - Binary Search 
// Time Complexity : O(log(max- min) * n*O(log(n))    Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int lesserElements(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        inc();

        int n = matrix.size();
        int ans = 0;
        int l = matrix[0][0], r = matrix[n - 1][n - 1];

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int result = lesserElements(matrix, mid, n);

            if (result >= k) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans;
    }
};
