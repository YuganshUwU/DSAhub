/*  LeetCode link : https://leetcode.com/problems/min-stack/
    Difficulty : Medium
*/

// Time Complexity : O(1)
// Space Complexity : O(n)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class MinStack {
public:
    vector<pair<int, int>> vec;

    MinStack() { inc(); }

    void push(int val) {
        if (vec.size() == 0)
            vec.push_back({val, val});
        else
            vec.push_back({val, min(val, vec.back().second)});
    }

    void pop() { 
        vec.pop_back();
    }

    int top() { 
        return vec.back().first; 
    }

    int getMin() { 
        return vec.back().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
