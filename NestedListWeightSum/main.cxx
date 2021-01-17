#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class Solution {
  public:
    int depthSum(vector<NestedInteger> &nestedList) {
        run_list(nestedList, 1);
    }
  private:
    int sum = 0;
    int run_list(const vector<NestedInteger> &nestedList, int depth) {
        for (const auto &list:nestedList) {
            run_node(list, depth);
        }
    }
    void run_node(const NestedInteger &list, int depth) {
        if (list.isInteger()) {
            sum += depth * list.getInteger();
        } else {
            run_list(list.getList(), depth + 1);
        }
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


