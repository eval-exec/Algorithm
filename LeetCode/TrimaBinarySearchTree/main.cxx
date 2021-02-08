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
        TreeNode* trimBST(TreeNode* root, int L, int H) {
            low = L;
            high = H;
            return trim(root);
        }
    private:
        int low = 0;
        int high = 0;
        TreeNode* trim(TreeNode* root){
            if (root == nullptr) return nullptr;
            if (root->val < low){
                return trim(root->right);
            }
            if (root->val > high){
                return trim(root->left);
            }
            root->left = trim(root->left);
            root->right = trim(root->right);
            return root;
        }
};



struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


