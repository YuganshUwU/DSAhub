/*  LeetCode link : https://leetcode.com/problems/design-circular-deque/
    Difficulty : Medium
*/

// Time Complexity : O(1)
// Space Complexity : O(K)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class MyCircularDeque {
public:
    vector<int> deque;
    int size;
    int currSize;
    int front, end;

    MyCircularDeque(int k) {
        inc();

        deque.resize(k);
        size = k;
        currSize = 0;
        front = 0;
        end = k - 1;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + size) % size;
        deque[front] = value;

        currSize++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        end = (end + 1) % size;
        deque[end] = value;

        currSize++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        currSize--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        end = (end - 1 + size) % size;
        currSize--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : deque[front]; }

    int getRear() { return isEmpty() ? -1 : deque[end]; }

    bool isEmpty() { return !currSize; }

    bool isFull() { return size == currSize; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
