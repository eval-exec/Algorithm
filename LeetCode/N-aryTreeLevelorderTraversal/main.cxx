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
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        queue<Node *> qq;
        qq.push(root);
        vector<vector<int>> rets;
        while (!qq.empty()) {
            int n = qq.size();
            vector<int> ret;
            while (n > 0) {
                Node *node = qq.front();
                qq.pop();
                ret.push_back(node->val);
                for (const auto &child: node->children) {
                    qq.push(child);
                }
                n--;
            }
            rets.push_back(ret);
        }
        return rets;
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


