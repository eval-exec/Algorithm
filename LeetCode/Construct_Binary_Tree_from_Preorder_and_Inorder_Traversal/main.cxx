#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Construct Binary Tree from Preorder and Inorder Traversal

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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  TreeNode *buildTree(vector<int> &preorder,
					  int pstart,
					  int pend,
					  vector<int> &inorder,
					  int istart,
					  int iend) {
	if (pstart > pend) {
	  return nullptr;
	} else if (pstart == pend) {
	  return new TreeNode(preorder[pstart]);
	} else {
	  int head = preorder[pstart];
	  int length = 0;
	  for (int j = istart; j <= iend; j++) {
		if (inorder[j] == head) {
		  TreeNode *left =
			  buildTree(preorder, pstart + 1, pstart + 1 + length - 1,
						inorder, istart, j - 1);
		  TreeNode *right =
			  buildTree(preorder, pstart + length + 1, pend,
						inorder, j + 1, iend);

		  return new TreeNode(head, left, right);
		}
		length++;
	  }
	  return nullptr;
	};
  }
};

//// END
struct T {

};

TEST(Solution, test) {
  T ts[] = {
	  {

	  },
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


