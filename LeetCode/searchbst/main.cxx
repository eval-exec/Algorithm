
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            if (!root){
                return nullptr;

            }
            if (root->val == val){
                return root;

            }
            TreeNode *l = searchBST(root->left,val);
            if (l){
                return l;

            }
            return searchBST(root->right,val);


        }

};
int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


