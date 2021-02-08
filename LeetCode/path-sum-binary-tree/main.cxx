
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
    int sum;
    bool expect;
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        if (isLeaf(root)) {
            return root->val == sum;
        }
        if (!root->left && !root->right) {
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

private:
    bool isLeaf(TreeNode *root) {
        if (!root) {
            return false;
        }
        return !root->left && !root->right;

    }
};

TEST(Solution, hasPathSum) {
    T ts[] = {
            {
                    {{5,  4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1}},
                    22,
                    true,
            },
            {
                    {{22}},
                    22,
                    true,
            },
            {
                    {{21, 2, 0}},
                    22,
                    false,
            },
            {
                    {{-1}},
                    0,
                    false,
            },
    };
    Solution solution;
    for (T t : ts) {
        cout << "checking" << endl;
        ASSERT_EQ(solution.hasPathSum(gen(t.nodes), t.sum), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


