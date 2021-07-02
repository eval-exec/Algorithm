#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Find Leaves of Binary Tree

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
  vector<vector<int>> findLeaves(TreeNode *root) {
	vector<vector<int>> rets;
	int depth = -1;
	findLeaves(rets, root, depth);
	return rets;
  }
  void findLeaves(vector<vector<int>> &rets, TreeNode *root, int &depth) {
	if (!root) {
	  depth = 0;
	  return;
	}
	int ldepth = -1, rdepth = -1;
	findLeaves(rets, root->left, ldepth);
	findLeaves(rets, root->right, rdepth);
	depth = max(ldepth, rdepth) + 1;
	if (rets.size() + 1 == depth) {
	  rets.push_back({root->val});
	} else {
	  rets[depth - 1].push_back(root->val);
	}
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


