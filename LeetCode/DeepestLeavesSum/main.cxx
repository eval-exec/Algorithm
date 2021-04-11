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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:

    int deepestLeavesSum(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> qq;
        qq.push(root);
        vector<TreeNode *> bottom;
        while (!qq.empty()) {
            int qlen = qq.size();
            bottom.clear();
            while (qlen > 0) {
                qlen--;
                auto now = qq.front();
                qq.pop();
                bottom.push_back(now);

                if (now->left) {
                    qq.push(now->left);
                }
                if (now->right) {
                    qq.push(now->right);
                }
            }
        }
        int ret = 0;
        for (auto b : bottom) {
            ret += b->val;
        }
        return ret;
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


