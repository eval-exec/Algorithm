
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
 * You must use only standard operations of a stack,
 * which means only push to top,
 * peek/pop from top,
 * size, and is empty operations are valid.
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        while (s1.size() != 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int peek = s1.top();
        s1.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return peek;
    }

    /** Get the front element. */
    int peek() {
        while (s1.size() != 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int peek = s1.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return peek;

    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


