#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        visit(root, p);
        return ret;
    }
  private:
    bool foundp = false;
    TreeNode *ret = nullptr;

    void visit(TreeNode *base, TreeNode *p) {
        if (base == nullptr)return;
        visit(base->left, p);
        if (foundp) {
            if (!ret) ret = base;
            return;
        }

        if (base->val == p->val) {
            foundp = true;
        }
        visit(base->right, p);
    }
};

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


