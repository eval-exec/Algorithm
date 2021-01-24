#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

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
    vector<TreeNode *> generateTrees(int n) {
        return gen(1, n);
    }
  private:
    vector<TreeNode *> gen(int left, int right) {
        vector<TreeNode *> rets;
        if (left > right) return rets;
        if (left == right) return {new TreeNode(left)};
        for (int i = left; i <= right; i++) {
            auto lefts = gen(left, i - 1);
            auto rights = gen(i + 1, right);
            if (lefts.empty()) {
                for (auto r: rights) {
                    auto node = new TreeNode(i);
                    node->right = r;
                    rets.push_back(node);
                }
            } else if (rights.empty()) {
                for (auto l: lefts) {
                    auto node = new TreeNode(i);
                    node->left = l;
                    rets.push_back(node);
                }
            } else {
                for (auto l: lefts) {
                    for (auto r: rights) {
                        auto node = new TreeNode(i);
                        node->left = l;
                        node->right = r;
                        rets.push_back(node);
                    }
                }
            }
        }
        return rets;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


