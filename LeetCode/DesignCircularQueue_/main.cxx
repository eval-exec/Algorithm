#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
/*
 *
 i*

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.

int Front() Gets the front item from the queue. If the queue is empty, return -1.

int Rear() Gets the last item from the queue. If the queue is empty, return -1.

boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.

boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.

boolean isEmpty() Checks whether the circular queue is empty or not.

boolean isFull() Checks whether the circular queue is full or not.

*/

class MyCircularQueue {
  private:
    vector<int> _vals;
    int _count = 0;
    int _len = 0;
    int _index = -1;
  public:
    MyCircularQueue(int k) {
        _len = k;
        _vals.resize(k);
        _index = k-1;
    }

    bool enQueue(int value) {
        if (_len == _count) return false;

        _count++;
        if (_index+1 == _len){
            _index = 0;
        }else{
            _index++;
        }
        _vals[_index] = value;
        return true;
    }

    bool deQueue() {
        if (_count == 0) return false;
        _count--;
        return true;
    }

    int Front() {
        if (_count == 0) return -1;
        int last = _index - _count+1;
        if (last < 0){
            last = _len + last;
        }
        return _vals[last];
    }

    int Rear() {
        if (_count == 0) return -1;
        return _vals[_index];
    }

    bool isEmpty() {
        return _count == 0;
    }

    bool isFull() {
        return _count == _len;
    }
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




struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


