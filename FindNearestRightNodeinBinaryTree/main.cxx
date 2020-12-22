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
	TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
	    queue<TreeNode*> qq;
	    qq.push(root);
	    while(!qq.empty()){
		int len = qq.size();
		while(len > 0){
		    TreeNode* now = qq.front();
		    qq.pop();
		    if (now->left)			qq.push(now->left);
		    if (now->right)			qq.push(now->right);


		    len--;
		    if (now == u){
			if (len == 0 ) return nullptr;
			return qq.front();
		    }
		}
	    }
	    return nullptr;
	}
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
	{

	},

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


