// Template for segment tree (this is for query sum, modify this as per requirement) 

class segTree {
  public:
    vector<int> sTree;
    
    segTree (int n) {
        sTree.resize(4 * n + 1);
    }
    
    void buildTree(int arr[], int i, int l, int r) {
        if (l == r) {
            sTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        buildTree(arr, 2 * i + 1, l, mid);
        buildTree(arr, 2 * i + 2, mid + 1, r);
        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    }
    
    void updateTree(int idx, int i, int l, int r, int val) {
        if (l == r) {
            sTree[i] = val;
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        if (idx <= mid) {
            updateTree(idx, 2 * i + 1, l, mid, val);
        } else {
            updateTree(idx, 2 * i + 2, mid + 1, r, val);
        }
        
        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    }
    
    int query(int l, int r, int start, int end, int i) {
        if (start > r || end < l)
            return 0;
        
        if (start >= l && end <= r) {
            return sTree[i];
        }
        
        int mid = l + (r - l ) / 2;
        return query(l, mid, start, end, 2 * i + 1) +
                query(mid + 1, r, start, end, 2 * i + 2);
    }
};
