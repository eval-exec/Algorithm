#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  private:
    stack<NestedInteger> st;
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it < nestedList.rend(); it++) {
            st.push(*it);
        }
    }

    int next() {
        auto top = st.top();
        st.pop();
        if (top.isInteger()) {
            return top.getInteger();
        }

        auto list = top.getList();
        for (auto it = list.rbegin(); it < list.rend(); it++) {
            st.push(*it);
        }

        return next();
    }
    bool hasNext() {
        if (st.empty()) return false;

        auto top = st.top();
        st.pop();
        if (top.isInteger()) {
            st.push(top);
            return true;
        }

        auto list = top.getList();
        for (auto it = list.rbegin(); it < list.rend(); it++) {
            st.push(*it);
        }

        return hasNext();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
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


