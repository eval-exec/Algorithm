#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

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
        vector<int> ret;
        travial(root, ret);
        return ret;
    }
  private:
    void travial(Node *root, vector<int> &ret) {
        if (!root) return;
        ret.push_back(root->val);
        for (auto n : root->children) {
            travial(n, ret);
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


