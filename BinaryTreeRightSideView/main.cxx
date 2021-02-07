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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> qq;

        vector<int> rets;
        qq.push(root);
        while(!qq.empty()){
            int qlen = qq.size();
            for (int i = qlen-1;i >= 0 ;i--){
                auto now = qq.front();
                qq.pop();
                if ( i == 0  ){
                    rets.push_back(now->val);
                }
                if (now->left) qq.push(now->left);
                if (now->right) qq.push(now->right);
            }
        }
        return rets;
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


