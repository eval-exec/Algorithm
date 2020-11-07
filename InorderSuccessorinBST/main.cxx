#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
        return find(nullptr, nullptr, root, p);
    }

private:
    TreeNode *find(TreeNode *MIN, TreeNode *MAX, TreeNode *root, TreeNode *p) {
        if (!root) {
            return nullptr;
        }
        if (p->val < root->val) {
            return find(MIN, root, root->left, p);
        } else if (p->val > root->val) {
            return find(root, MAX, root->right, p);
        } else {
            if (root->right) {
                root = root->right;
                while (root && root->left) {
                    root = root->left;
                }
                return root;
            } else {
                return MAX;
            }
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


