/*  LeetCode link : https://leetcode.com/problems/design-circular-queue/
    Difficulty : Medium
*/

// Time Complexity : O(1)
// Space Complexity : O(K)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class MyCircularQueue {
public:

    vector<int> que;
    int front, last;
    int size, currSize;

    MyCircularQueue(int k) {
        inc();

        que.resize(k);
        currSize = 0;
        front = 0;
        last = k - 1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        last = (last + 1) % size;
        que[last] = value;

        currSize++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        currSize--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : que[front]; }

    int Rear() { return isEmpty() ? -1 : que[last]; }

    bool isEmpty() { return !currSize; }

    bool isFull() { return currSize == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
