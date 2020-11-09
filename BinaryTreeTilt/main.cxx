#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
Given the root of a binary tree,
return the sum of every tree node's tilt.
The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values.

If a node does not have a left child,
then the sum of the left subtree node values is treated as 0.
The rule is similar if there the node does not have a right child.
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
    // help return sum of all child node, and reference of tilt.
    int help(TreeNode *node, int &tilt) {
        if (node == nullptr) {
            tilt = 0;
            return 0;
        }
        if (!node->left && !node->right) {
            tilt = 0;
            return node->val;
        }
        int leftTiltSum = 0, rightTiltSum = 0;
        int sumLeft = help(node->left, leftTiltSum);
        int sumRight = help(node->right, rightTiltSum);

        tilt = abs(sumLeft - sumRight) + leftTiltSum + rightTiltSum;

        return sumLeft + sumRight + node->val;
    }

public:
    int findTilt(TreeNode *root) {
        int t = 0;
        help(root, t);
        return t;
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


