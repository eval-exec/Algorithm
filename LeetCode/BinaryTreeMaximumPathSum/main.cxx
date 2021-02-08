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
    int maxPathSum(TreeNode *root) {
        path(root);
        return maxSum;
    }

private:
    int path(TreeNode *root) {

        if (root == nullptr) return INT_MIN;
        int ret1 = root->val, ret2 = root->val;
        maxSum = max(maxSum, root->val);
        int left = 0;
        int right = 0;
        if (root->left) {
            left = path(root->left);
            ret1 = max(ret1, root->val + left);
            maxSum = max(maxSum, root->val + left);
        }
        if (root->right) {
            right = path(root->right);
            ret2 = max(ret2, root->val + right);
            maxSum = max(maxSum, root->val + right);
        }
        if (root->left && root->right) {
            maxSum = max(maxSum, root->val + left + right);
        }

        return max(ret1, ret2);
    }

    int maxSum = INT_MIN;
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


