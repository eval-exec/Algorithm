
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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        vector<int> ret;
        ret.push_back(root->val);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


