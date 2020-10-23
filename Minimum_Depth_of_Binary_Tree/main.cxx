
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
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return dig(root, 1);
    }

private:
    int dig(TreeNode *node, int depth) {
        if (!node->left && !node->right) {
            return depth;
        }
        if (!node->left) {
            return dig(node->right, depth + 1);
        }
        if (!node->right) {
            return dig(node->left, depth + 1);
        }
        return min(dig(node->left, depth + 1), dig(node->right, depth + 1));
    }
};

/*
 *
 * class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right){
            return minDepth(root->right) + 1;
        }
        if(root->right == NULL && root->left){
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
 */

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


