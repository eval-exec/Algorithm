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
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        unordered_map<TreeNode *, TreeNode *> mm;
        queue<TreeNode *> qq;
        qq.push(root);
        unordered_set<TreeNode *> back;
        while (!qq.empty()) {
            int len = qq.size();
            while (len > 0) {
                TreeNode *node = qq.front();
                back.insert(node);
                qq.pop();

                if (node->left) {
                    mm[node->left] = node;
                    qq.push(node->left);
                }
                if (node->right) {
                    mm[node->right] = node;
                    qq.push(node->right);
                }
                len--;
            }
            if (qq.empty()) {
                break;
            } else {
                back.clear();
            }
        }
        while (back.size() != 1) {
            unordered_set<TreeNode *> tmp;
            for (auto b : back) {
                auto f = mm[b];
                tmp.insert(f);
            }
            back = tmp;
        }
        return *back.begin();
    }
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


