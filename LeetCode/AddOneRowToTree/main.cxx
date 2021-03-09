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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return nullptr;
        if (d == 1){
            auto tmp = new TreeNode(v);
            tmp->left = root;
            return  tmp;
        }
        queue<TreeNode*> qq;
        qq.push(root);
        int depth = 1;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen>0){
                qlen--;
                auto now = qq.front();
                qq.pop();
                if (depth + 1 == d){
                    if (now->left){
                        auto tmp= new TreeNode(v);
                        tmp->left = now->left;
                        now->left = tmp;
                    }else{
                        now->left = new TreeNode(v);
                    }
                    if (now->right){
                        auto tmp= new TreeNode(v);
                        tmp->right = now->right;
                        now->right = tmp;
                    }else{
                        now->right = new TreeNode(v);
                    }
                }else{
                    if (now->left) qq.push(now->left);
                    if (now->right) qq.push(now->right);
                }
            }
            depth++;
            if (depth == d) break;
        }
        return root;
    }
};




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


