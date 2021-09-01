#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Average Subtree

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
	double maximumAverageSubtree(TreeNode* root) {
		double sum =0;int count=0;
		run(root,sum,count);
		return maxAve;
	}
	void run(TreeNode* root, double &sum, int &count){
		if (!root) return ;
		double leftsum = 0;
		double rightsum = 0;
		int leftcount = 0;
		int rightcount = 0;
		run(root->left, leftsum,leftcount);
		run(root->right,rightsum,rightcount);
		sum = leftsum+ rightsum + root->val;
		count = 1 + leftcount + rightcount;
		maxAve = max(maxAve, sum/ count);
	}
	private:
	double maxAve = 0;
	unordered_map<TreeNode*,double> msum;
	unordered_map<TreeNode*,int> mcount;
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


