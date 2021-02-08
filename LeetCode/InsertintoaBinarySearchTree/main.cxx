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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode *ROOT = root;
        while (root) {
            if (val > root->val) {
                if (root->right) {
                    root = root->right;
                } else {
                    root->right = new TreeNode(val);
                    break;
                }
            } else {
                if (root->left) {
                    root = root->left;
                } else {
                    root->left = new TreeNode(val);
                    break;
                }
            }
        }
        return ROOT;

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


