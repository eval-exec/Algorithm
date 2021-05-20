#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Binary Tree Level Order Traversal 001

*/

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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> qq;
        qq.push(root);
        vector<vector<int>> rets;
        while(!qq.empty()){
            int qlen = qq.size();
            vector<int> level;
            while(qlen > 0){
                qlen--;
                auto now = qq.front();
                qq.pop();
                
                level.push_back(now->val);
                if (now->left) qq.push(now->left);
                if (now->right) qq.push(now->right);

            }
            rets.push_back(level);
        }
        return rets;
    }
};


//// END
struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
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


