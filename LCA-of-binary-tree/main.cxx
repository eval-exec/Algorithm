
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

/*
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
 */


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

void print(vector<int> ns) {
    cout << "{";
    for (int n: ns) {
        cout << n << " ";
    }
    cout << "}";
    cout << endl;
}

struct T {
    vector<int> ndoes;

    int expect;
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        map<TreeNode *, TreeNode *> mm;
        map<TreeNode *, int> md;
        mm[root] = root;
        md[root] = 1;
        dig(root, md, mm, 2);
        return find(md, mm, p, q);
    }

private:
    TreeNode *find(map<TreeNode *, int> &md, map<TreeNode *, TreeNode *> &mm, TreeNode *p, TreeNode *q) {
        if (p == q) {
            return q;
        }
        int pd = md[p];
        int qd = md[q];
        if (pd > qd) {
            int n = pd - qd;
            while (n) {
                p = mm[p];
                n--;
            }
        } else {
            if (qd > pd) {
                int n = qd - pd;
                while (n) {
                    q = mm[q];
                    n--;
                }
            }
        }
        while (p != q) {
            p = mm[p];
            q = mm[q];
        }
        return p;
    }

    void dig(TreeNode *node, map<TreeNode *, int> &md, map<TreeNode *, TreeNode *> &m, int depth) {
        if (!node->left && !node->right) {
            return;
        }
        if (node->left) {
            m[node->left] = node;
            md[node->left] = depth;
            dig(node->left, md, m, depth + 1);
        }
        if (node->right) {
            m[node->right] = node;
            md[node->right] = depth;
            dig(node->right, md, m, depth + 1);
        }
    }
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root or p == root or q == root)return root;
        TreeNode *t1, *t2;
        t1 = lowestCommonAncestor(root->left, p, q);
        t2 = lowestCommonAncestor(root->right, p, q);
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        if (t1 && t2) {
            return root;
        }
        if (!t1) {
            return t2;
        } else {
            return t1;
        }
    }
};

TEST(Solution, LCA) {
    Solution solution;
    T ts[] = {
            {

            }
    };


}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


