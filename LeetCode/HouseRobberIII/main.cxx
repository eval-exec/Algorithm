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
    int rob(TreeNode *root) {
        auto r = dp(root);
        return max(r.first, r.second);
    }

private:
    pair<int, int> dp(TreeNode *root) {
        if (root == nullptr) return make_pair(0, 0);
        auto f = mm.find(root);
        if (f != mm.end()) {
            return {f->second.first, f->second.second};
        }


        auto left = dp(root->left);
        auto right = dp(root->right);
        auto ret = make_pair(root->val + left.second + right.second,
                             max(left.first, left.second) + max(right.first, right.second));
        mm[root] = ret;
        return ret;
    }

    map<TreeNode *, pair<int, int>> mm;
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


