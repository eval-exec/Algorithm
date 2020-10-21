
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
    vector<int> inorder;
    vector<int> postorder;
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int lenI = inorder.size();
        int lenP = postorder.size();
        if (lenI == 0) {
            return nullptr;
        }
        if (lenP == 0) {
            return nullptr;
        }

        int valRoot = postorder[lenP - 1];
        TreeNode *root = new TreeNode(valRoot);

        if (lenP == 1) {
            return root;
        }

        int indexRootInOrder = 0;
        for (int i = 0; i < lenI; i++) {
            if (inorder[i] == valRoot) {
                indexRootInOrder = i;
                break;
            }
        }

        vector<int> newLeftIn(inorder.begin(), inorder.begin() + indexRootInOrder);
        vector<int> newLeftPost(postorder.begin(), postorder.begin() + indexRootInOrder);

        TreeNode *left = buildTree(newLeftIn, newLeftPost);

        vector<int> newRightIn(inorder.begin() + indexRootInOrder + 1, inorder.end());
        vector<int> newRightPost(postorder.begin() + indexRootInOrder, postorder.end() - 1);


        TreeNode *right = buildTree(newRightIn, newRightPost);
        root->left = left;
        root->right = right;
        return root;
    }
};

TEST(Solution, construct_binary_tree) {
    T ts[] = {
            {
                    {{9, 3, 15, 20, 7}},
                    {{9, 15, 7, 20, 3}},
                    {{3, 9, 20, -1, -1, 15, 7}},

            }
    };
    Solution solution;
    for (T t : ts) {
        print(t.inorder);
        print(t.postorder);
        print(t.nodes);

        TreeNode *pNode = solution.buildTree(t.inorder, t.postorder);
        vector<int> dump1 = dump(pNode);
        print(dump1);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


