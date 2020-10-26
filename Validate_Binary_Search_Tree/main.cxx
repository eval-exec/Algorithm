
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
        return valid(root->left, LONG_MIN, root->val)
               && valid(root->right, root->val, LONG_MAX);
    }

    bool valid(TreeNode *root, long min, long max) {
        if (!root) {
            return true;
        }
        if (min >= root->val || root->val >= max) {
            return false;
        }
        if (!root->left) {
            return valid(root->right, root->val, max);
        }
        if (!root->right) {
            return valid(root->left, min, root->val);
        }
        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


