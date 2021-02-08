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
    int findDistance(TreeNode *root, int p, int q) {
        TreeNode* lca = LCA(root,p,q);
        queue<TreeNode*> qq;
        qq.push(lca);
        int dp = -1;
        int dq = -1;
        int dd = 0;
        while(!qq.empty() && (dp == -1 && dq == -1)){
            int qlen = qq.size();
            while(qlen> 0){
                auto now = qq.front();
                qq.pop();
                if (now->val == p){
                    dp = dd;
                }
                if (now->val == q){
                    dq = dd;
                }
                if (now->left) qq.push(now->left);
                if (now->right) qq.push(now->right);

                qlen--;
            }
            dd++;
        }
        return dp+dq;
    }
  private:
    TreeNode* LCA(TreeNode *root,int p,int q){
        if (root == nullptr) return nullptr;
        if (root->val == p || root->val == q) return root;
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if (left != nullptr && right != nullptr ) return root;
        if (left != nullptr ) return left;
        if (right != nullptr ) return right;
        return nullptr;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


