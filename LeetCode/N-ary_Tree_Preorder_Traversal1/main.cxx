#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START ## N-ary Tree Preorder Traversal1

/*
// Definition for a Node.
*/


class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
  public:
    vector<int> preorder(Node *root) {
        vector<int> rets;
        travel(rets, root);
        return rets;
    }
    void travel(vector<int> &rets, Node *node) {
        if (!node) return;
        rets.push_back(node->val);
        for (const auto child: node->children) {
            travel(rets, child);
        }
    }
};



//// END




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


