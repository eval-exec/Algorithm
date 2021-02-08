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
private:
    TreeNode *findSuccessor(TreeNode *root) {
        TreeNode *cur = root->right;
        while (cur && cur->left) {
            cur = cur->left;
        }
        return cur;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            TreeNode *suc = findSuccessor(root);
            if (!suc) {
                return root->left;
            }
            root->val = suc->val;
            root->right = deleteNode(root->right, suc->val);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
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


