#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Two Sum IV - Input is a BST

*/

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
	bool findTarget(TreeNode* root, int k) {
		queue<TreeNode*> qq;
		qq.push(root);
		unordered_map<int,bool> mm;
		while(!qq.empty()){
			int qlen = qq.size();
			while(qlen > 0){
				qlen--;
				auto now = qq.front();
				qq.pop();
				if (mm[k- now->val]){
					return true;
				}
				mm[now->val]=true;
				if (now->left)qq.push(now->left);
				if (now->right)qq.push(now->right);
			}
		}
		return false;
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


