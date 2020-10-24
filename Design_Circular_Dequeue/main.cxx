
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        _queue = vector<int>(k);
        _head = -1;
        _tail = -1;
        _max = k - 1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            _queue[0] = value;
            _head = _tail = 0;
            return true;
        } else {
            if (_tail == _max) {
                _queue[0] = value;
                _tail = 0;
                return true;
            } else {
                _queue[_tail + 1] = value;
                _tail++;
                return true;
            }
        }
    }

/** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (_head <= _tail) {
            _head++;
            if (_head > _tail) {
                _head = _tail = -1;
            }
            return true;
        } else {
            _head++;
            if (_head == _tail) {
                _head = _tail = -1;
                return true;
            }
            return true;
        }
    }

/** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return _queue[_head];
    }

/** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return _queue[_tail];
    }

/** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return _head == -1;
    }

/** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (isEmpty()) {
            return false;
        }
        if (_head == 0) {
            return _tail == _max;
        } else {
            return _tail == _head - 1;
        }
    }

private:
    vector<int> _queue;
    int _head, _tail, _max;
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


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


