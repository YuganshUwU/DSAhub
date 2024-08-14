/*  Leetcode link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/
    Difficulty : Hard
*/

// Approach 1 - Using Priority Queue 
// Time Complexity : O(n^2 * log(k)) TLE
// Space Complexity : O(k)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        inc();

        int n = nums.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pq.push(abs(nums[i] - nums[j]));

                if (pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};

------------------------------------------------------------------------------------------------------------------------------------

// Approach 2 - Optimized Brute Force method
// Time Complexity : O(n^2 + size)
// Space Complexity : O(maximum value)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        inc();

        int n = nums.size();
        int size = *max_element(nums.begin(), nums.end());
        vector<int> freq(size + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                freq[diff]++;
            }
        }

        for (int i = 0; i <= size; i++) {
            k -= freq[i];

            if (k <= 0)
                return i;
        }

        return -1;
    }
};

------------------------------------------------------------------------------------------------------------------------------------

// Approach 3 - Same approach 2 but using STL
// Time Complexity : O(n^2 + n^2) -> average Time Complexity of nth_element function is O(n) and worst case Time Complexity is O(n^2)
// Space Complexity : O(n^2)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        inc();

        int n = nums.size();
        vector<int> freq(n * (n - 1) / 2, 0);
        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                freq[idx++] = diff;
            }
        }

        nth_element(freq.begin(), freq.begin() + (k - 1), freq.end());
        return freq[k - 1];
    }
};

------------------------------------------------------------------------------------------------------------------------------------

// Approach 4 - Binary Search + Sliding Window
// Time Complexity : O(n * log(M) + nlog(n)) -> M = maximum value - minimum value
// Space Complexity : O(1)
  
#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int countingPairs(vector<int>& nums, int dist) {
        int n = nums.size();
        int i = 0, j = 1;
        int result = 0;

        while (j < n) {
            while (nums[j] - nums[i] > dist)
                i++;

            result += j - i;
            j++;
        }

        return result;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        inc();

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int pairs = countingPairs(nums, mid);

            if (pairs >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
