// note that this template is for query sum (lazy variant), update the code as per your requirement

#include<bits/stdc++.h>
using namespace std;

class segTree {
  public:
    vector<int> sTree, lazy;
    
    segTree (int n) {
        sTree.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }
    
    void buildTree (vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            sTree[i] = nums[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        buildTree(nums, 2 * i + 1, l, mid);
        buildTree(nums, 2 * i + 2, mid + 1, r);
        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    }

    void lazyUpdation (int i, int l, int r, int start, int end, int val) {
        
        if (lazy[i]) {
            sTree[i] += (r - l + 1) * lazy[i];
            
            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            
            lazy[i] = 0;
        }
        
        if (start > r || end < l)
            return;
        
        if (start <= l && end >= r) {
            sTree[i] += (r - l + 1) * val;
            if(l != r) {
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
            }
            
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        lazyUpdation(i, l, mid, start, end, val);
        lazyUpdation(i, mid + 1, r, start, end, val);
        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    }

    int lazyQuery (int i, int l, int r, int start, int end) {
        
        if (lazy[i]) {
            sTree[i] += (r - l + 1) * lazy[i];
            
            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            
            lazy[i] = 0;
        }
        
        if (start > r || end < l)
            return 0;
        
        if (start <= l && end >= r) 
            return sTree[i];
        
        int mid = l + (r - l) / 2;
        return lazyQuery(2 * i + 1, l, mid, start, end) +
                lazyQuery(2 * i + 2, mid + 1, r, start, end);
    }
};
