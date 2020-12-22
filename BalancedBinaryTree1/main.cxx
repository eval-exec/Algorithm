#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
	: val(0)
	  , left(nullptr)
	  , right(nullptr){    }
    TreeNode(int x)
	: val(x)
	  , left(nullptr)
	  , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
	: val(x)
	  , left(left)
	  , right(right)
    {
    }
};

class Solution {
    public:
	bool isBalanced(TreeNode* root){
	    int h=0;
	    return isBalanced(root,h);
	}
    private:
	bool isBalanced(TreeNode* root,int &height){
	    if (!root) {
		height = 0;
		return true;
	    }
	    if (!root->left && !root->right) {
		height = 1;
		return true;
	    }
	    int h1 = 0,h2 = 0;
	    bool b1 = isBalanced(root->left,h1);
	    if (!b1) return false;
	    bool b2 = isBalanced(root->right,h2);
	    if (!b2) return false;
	    height = 1+max(h1,h2);
	    return abs(h1-h2) <=1;
	}
};

struct T {
};

TEST(Solution, test)
{
    T ts[] = {
	{

	},

    };

    Solution solution;

    for (T t : ts) {
    }
}

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
