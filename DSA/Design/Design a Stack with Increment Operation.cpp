/*  LeetCode link : https://leetcode.com/problems/design-a-stack-with-increment-operation/
    Difficulty : Medium
*/

// Approach - Lazy Propagation

// Time Complexity : O(1)
// Space Complexity : O(N)

#define incl()                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class CustomStack {
public:
    vector<int> st;
    vector<int> incr;
    int n;

    CustomStack(int maxSize) {
        incl();
        n = maxSize;
    }

    void push(int x) {
        if (st.size() >= n)
            return;

        st.push_back(x);
        incr.push_back(0);
    }

    int pop() {
        if (st.empty())
            return -1;

        int idx = st.size() - 1;
        if(idx > 0)
            incr[idx - 1] += incr[idx];
        
        int val = st[idx] + incr[idx];
        st.pop_back();
        incr.pop_back();

        return val;
    }

    void increment(int k, int val) {
        int lim = min(k, (int)st.size()) - 1;
        if(lim >= 0)
            incr[lim] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
