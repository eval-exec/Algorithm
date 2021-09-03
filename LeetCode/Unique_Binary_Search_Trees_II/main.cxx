#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Unique Binary Search Trees II

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
	vector<TreeNode*> generateTrees(int n) {
		return generateTrees(1,n);
	}
	vector<TreeNode*> generateTrees(int start, int end) {
		if (start > end) return vector<TreeNode*>{nullptr};
		if (start == end) return vector<TreeNode*>{new TreeNode(start)};
		vector<TreeNode*> rets;
		for (int index = start;index<= end;index++){
			for (auto left : generateTrees(start,index - 1)){
				for (auto right: generateTrees(index+1,end)){
					TreeNode* head = new TreeNode(index,left,right);
					rets.push_back(head);
				}
			}
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


