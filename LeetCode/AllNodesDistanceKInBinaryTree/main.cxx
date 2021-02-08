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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        if (K == 0) return {target->val};
        vector<int> rets;
        build(root);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> qq;
        qq.push(target);
        visited[target] = true;
        int k = 0;
        while (!qq.empty()) {
            int n = qq.size();
            while (n > 0) {
                const auto now = qq.front();
                qq.pop();
                const auto &p = pp[now];
                if (p && !visited[p]) {
                    visited[p] = true;
                    qq.push(p);
                }
                if (now->left && !visited[now->left]) {
                    visited[now->left] = true;
                    qq.push(now->left);
                }
                if (now->right && !visited[now->right]) {
                    visited[now->right] = true;
                    qq.push(now->right);
                }
                if (k == K) rets.push_back(now->val);
                n--;
            }
            k++;
        }
        return rets;
    }

    unordered_map<TreeNode *, TreeNode *> pp;
  private:
    void build(TreeNode *root) {
        if (root->left) {
            pp[root->left] = root;
            build(root->left);
        }
        if (root->right) {
            pp[root->right] = root;
            build(root->right);
        }
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


