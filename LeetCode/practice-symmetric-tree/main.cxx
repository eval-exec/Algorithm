
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int get(vector<int> nodes, int i) {
    if (nodes.size() <= i) {
        return -1;
    }
    return nodes[i];
}

TreeNode *_gen(vector<int> &nodes, int i) {
    int val = get(nodes, i);
    if (val < 0) {
        return nullptr;
    }
    TreeNode *l = _gen(nodes, 2 * i + 1);
    TreeNode *r = _gen(nodes, 2 * i + 2);

    return new TreeNode(val, l, r);
}

TreeNode *gen(vector<int> &nodes) {
    return _gen(nodes, 0);
}

struct T {
    vector<int> nodes;
    bool expect;
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return equal(root->left, root->right);
    }

private:
    bool equal(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        return left->val == right->val && equal(left->left, right->right) && equal(left->right, right->left);
    }
};

TEST(Solution, isSymmetric) {
    T ts[] = {
            {
                    {{1, 2, 2, 3,  4, 4,  3}},
                    true,
            },
            {
                    {{1, 2, 2, -1, 3, -1, 3}},
                    false,
            },
            {
                    {{1, 2, 3}},
                    false,
            },
            {
                    {{1, 2, 2}},
                    true,
            },
            {
                    {{1}},
                    true,
            },
            {
                    {{1, 2}},
                    false,
            },
    };

    Solution solution;
    for (T t: ts) {
        ASSERT_EQ(solution.isSymmetric(gen(t.nodes)), t.expect);
    }
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


