
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

vector<int> dump(TreeNode *root) {
    list<TreeNode *> mm;
    mm.push_back(root);

    vector<int> ret;

    int lastL = 0;
    while (!mm.empty()) {
        int len = mm.size();
        lastL = len;
        bool did = false;
        while (len > 0) {
            TreeNode *f = mm.front();
            mm.pop_front();

            if (!f) {
                ret.push_back(-1);
                len--;
                continue;
            } else {
                ret.push_back(f->val);
                did = true;
            }
            if (f->left) {
                mm.push_back(f->left);
            } else {
                mm.push_back(nullptr);
            }
            if (f->right) {
                mm.push_back(f->right);
            } else {
                mm.push_back(nullptr);
            }
            len--;
        }
        if (!did) {
            ret.erase(ret.end() - lastL, ret.end());
        }
    }
    return ret;
}

struct T {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> nodes;
};

void print(vector<int> ns) {
    cout << "{";
    for (int n: ns) {
        cout << n << " ";
    }
    cout << "}";
    cout << endl;
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, int> mm;
        for (int i = 0; i < inorder.size(); i++) {
            mm[inorder[i]] = i;
        }
        int len = inorder.size();
        return build(preorder, inorder, mm, 0, 0, len);
    }

private:
    TreeNode *
    build(vector<int> &preorder, vector<int> &inorder, map<int, int> &mm, int prestart, int instart, int len) {
        if (len <= 0) {
            return nullptr;
        }
        int preVal = preorder[prestart];
        TreeNode *root = new TreeNode(preVal);

        if (len == 1) {
            return root;
        }
        int inIndex = mm[preVal];

        int llen = inIndex - instart;

        int rlen = len - llen - 1;

        /*
         * [4,3,1,2]
         * [1,2,3,4]
         */

        TreeNode *left = build(preorder, inorder, mm,
                               prestart + 1, instart, llen);

        TreeNode *right = build(preorder, inorder, mm,
                                prestart + 1 + llen, instart + 1 + llen, rlen);
        root->left = left;
        root->right = right;
        return root;
    }
};

TEST(Solution, buildTree) {
    T ts[] = {
            {
                    {{3, 9, 20, 15, 7}},
                    {{9, 3, 15, 20, 7}},
                    {{3, 9, 20, -1, -1, 15, 7}},
            },
            {
                    {{4, 3, 1,  2}},
                    {{1, 2, 3,  4}},
                    {{4, 3, -1, 1,  -1, -1, 2}},
            },
    };
    Solution solution;
    for (T t : ts) {
        print(t.preorder);
        print(t.inorder);
        print(t.nodes);
        TreeNode *pNode = solution.buildTree(t.preorder, t.inorder);
        print(dump(pNode));
        cout << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


