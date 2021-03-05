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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (!root) return ret;

        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()){
            int qlen = qq.size();
            int n = qlen;
            long sum = 0;
            while(qlen > 0){
                qlen--;
                auto now = qq.front();
                qq.pop();
                sum += now->val;
                if (now->left) qq.push(now->left);
                if (now->right) qq.push(now->right);
            }
            ret.push_back(sum/double(n));
        }
        return ret;
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


