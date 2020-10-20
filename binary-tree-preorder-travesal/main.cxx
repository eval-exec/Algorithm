
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        vector<int> ret;
        ret.push_back(root->val);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};


int get(vector<int> nodes, int i) {
    if (nodes.size() <= i) {
        return -1;
    }
    return nodes[i];
}

/*
 *
 * 0
 * 1,2
 * 3,4  5,6
 * 7,8, 9,10 , 11,12 ,  13,14
 * 14,16 17,18,   19,20
 */

#include <iterator> // needed for std::ostram_iterator

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

TEST(Solution, preOrderTravesal) {
    Solution solution;
    vector<int> result;

    T ts[] = {
            {
                    {{1, 2,  3, 4, 5, 6}}
            },
            {
                    {{1, -1, 2}}
            },
    };

    vector<int> nodes = {1, 2, 3, 4, 5, 6};
    TreeNode *pNode = gen(nodes);

    for (T t: ts) {
        cout << "checking ..." << endl;
        cout << t.nodes << endl;
        result = solution.preorderTraversal(gen(t.nodes));
        cout << result << endl;
    }

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


