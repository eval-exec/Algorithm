#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Flatten Binary Tree to Linked List

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
    void flatten(TreeNode *root) {
        if (!root) return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = nullptr;

        flatten(left);
        flatten(right);

        if (left) {
            root->right = left;
        }
        while (root->right) {
            root = root->right;
        }
        root->right = right;
    }
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


