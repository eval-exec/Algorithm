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
    int pseudoPalindromicPaths(TreeNode *root) {
        if (!root) return 0;
        array<int, 10> mm = {0};
        int count = 0;
        dfs(root, mm, count);
        return count;
    }
  private:
    void dfs(TreeNode *node, array<int, 10> &mm, int &count) {
        mm[node->val] += 1;
        if (!node->left && !node->right) {
            int cc = 0;
            int single = 0;
            for (int i = 0; i < 10; i++) {
                if (mm[i] == 0) continue;
                cc += mm[i];
                if (mm[i] % 2 != 0) {
                    single++;
                }
            }
            if (cc % 2 == 0) {
                if (single == 0) count++;
            } else {
                if (single == 1) count++;
            }
        }
        if (node->left) {
            dfs(node->left, mm, count);
        }
        if (node->right) {
            dfs(node->right, mm, count);
        }
        mm[node->val] -= 1;
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


