/*  LeetCode link : https://leetcode.com/problems/range-sum-query-mutable/
    Difficulty : Medium
*/

// Time Complexity : for constructor and buildSegmentTree -> O(n) else O(log n)
// Space Complexity : O(4 * n) - > O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class NumArray {
public:
    vector<int> segTree;
    int n;

    NumArray(vector<int>& nums) {
        inc();

        n = nums.size();
        segTree.resize(4 * n);

        buildSegmentTree(nums, 0, 0, n - 1);
    }

    void buildSegmentTree(vector<int>& nums, int idx, int start, int end) {
        if (start == end) {
            segTree[idx] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        buildSegmentTree(nums, 2 * idx + 1, start, mid);
        buildSegmentTree(nums, 2 * idx + 2, mid + 1, end);

        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    void updateUtil(int idx, int val, int i, int start, int end) {
        if (start == end) {
            segTree[i] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx <= mid)
            updateUtil(idx, val, 2 * i + 1, start, mid);
        else
            updateUtil(idx, val, 2 * i + 2, mid + 1, end);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update(int index, int val) { updateUtil(index, val, 0, 0, n - 1); }

    int sumRangeQuery(int left, int right, int i, int start, int end) {
        int mid = start + (end - start) / 2;

        if (right < start || left > end)
            return 0;
        else if (left <= start && right >= end)
            return segTree[i];

        return sumRangeQuery(left, right, 2 * i + 1, start, mid) +
               sumRangeQuery(left, right, 2 * i + 2, mid + 1, end);
    }

    int sumRange(int left, int right) {
        return sumRangeQuery(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
