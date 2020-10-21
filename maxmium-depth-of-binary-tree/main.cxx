
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/*
 * maximum depth of binary tree
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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return max(left, right);
    }
};


TreeNode *_gen(vector<int> &nodes, int i) {
    int val = [](const vector<int> &ns, const int &i) -> int {
        if (ns.size() <= i) {
            return -1;
        }
        return ns[i];
    }(nodes, i);
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

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    out << "{";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "}";
    return out;
}


struct T {
    vector<int> nodes;
};

TEST(Solution, maximium_depth_of_binary_tree) {
    Solution solution;

    T ts[] = {
            {
                    {{1, 2, 3}},
            },
            {
                    {{3, 9, 20, -1, -1, 15, 7}},
            },
            {
                    {{1}},
            },
            {
                    {{0}},
            },
    };

    for (T t: ts) {

        for (int v:t.nodes) {
            cout << v << " ";
        }
        cout << endl;

        int result = solution.maxDepth(gen(t.nodes));
        printf("result is %d \n", result);
    }

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


