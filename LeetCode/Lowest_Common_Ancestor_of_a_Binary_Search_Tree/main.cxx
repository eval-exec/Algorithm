#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Lowest Common Ancestor of a Binary Search Tree

*/


/**
 * Definition for a binary tree node.
 */


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (p->val > q->val)swap(p, q);
	if (!root) return nullptr;
	if (root->val == p->val || root->val == q->val) return root;
	if (root->val > p->val && root->val < q->val) return root;
	if (root->val < p->val)return lowestCommonAncestor(root->right, p, q);
	if (root->val > q->val)return lowestCommonAncestor(root->left, p, q);
	return nullptr;
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


