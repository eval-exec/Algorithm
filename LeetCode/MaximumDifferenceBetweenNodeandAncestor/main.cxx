#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
 *
Given the root of a binary tree,

find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val|
 and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B,

or any child of A is an ancestor of B.

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
    int M = 0;

    void help(TreeNode *node, int &mx, int &mn) {
        if (!node->left && !node->right) {
            mx = node->val;
            mn = node->val;
            return;
        }

        mx = 0;
        mn = 1e5;
        if (node->left) {
            int lmax = 0, lmin = 1e5;
            help(node->left, lmax, lmin);
            mx = max(mx, lmax);
            mn = min(mn, lmin);
        }
        if (node->right) {
            int rmax = 0, rmin = 1e5;
            help(node->right, rmax, rmin);
            mx = max(mx, rmax);
            mn = min(mn, rmin);
        }
        M = max(M, abs(node->val - mx));
        M = max(M, abs(node->val - mn));
        mx = max(mx, node->val);
        mn = min(mn, node->val);
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        int mx = 0, mn = 0;
        help(root, mx, mn);
        return M;
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


