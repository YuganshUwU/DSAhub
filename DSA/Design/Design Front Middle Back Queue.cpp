/*  LeetCode link : https://leetcode.com/problems/design-front-middle-back-queue/
    Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(N)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class FrontMiddleBackQueue {
public:
    vector<int> que;

    FrontMiddleBackQueue() {
        inc();
    }

    void pushFront(int val) { que.insert(que.begin(), val); }

    void pushMiddle(int val) {
        int n = que.size() / 2;
        que.insert(que.begin() + n, val);
    }

    void pushBack(int val) { que.push_back(val); }

    int popFront() {
        if (!que.size())
            return -1;

        int val = que.front();
        que.erase(que.begin());
        return val;
    }

    int popMiddle() {
        if (que.empty())
            return -1;

        int n = (que.size() - 1) / 2;
        int val = que[n];

        que.erase(que.begin() + n);
        return val;
    }

    int popBack() {
        if (que.empty())
            return -1;

        int val = que.back();
        que.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
