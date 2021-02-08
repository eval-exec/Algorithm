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
    TreeNode *increasingBST(TreeNode *root) {
        ret = new TreeNode();
        TreeNode *head = ret;
        cal(root);
        return head->right;
    }

private:
    TreeNode *ret;

    void cal(TreeNode *root) {
        if (!root) {
            return;
        }
        cal(root->left);
        ret->right = root;
        root->left = nullptr;
        ret = ret->right;
        cal(root->right);
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


