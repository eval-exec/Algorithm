#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a Node.
 */

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;
    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

class Solution {
  public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        if (root == nullptr) return nullptr;
        NodeCopy *rootDup = clone(root);
        queue<Node *> qq;
        qq.push(root);
        while (!qq.empty()) {
            int qlen = qq.size();
            while (qlen > 0) {
                qlen--;
                auto now = qq.front();
                qq.pop();
                if (now->random != nullptr) {
                    get(now)->random = get(now->random);
                }
                if (now->left) {
                    qq.push(now->left);
                }
                if (now->right) {
                    qq.push(now->right);
                }
            }
        }
        return rootDup;
    }

  private:
    NodeCopy *clone(Node *root) {
        if (root == nullptr) return nullptr;
        NodeCopy *l = clone(root->left);
        NodeCopy *r = clone(root->right);
        NodeCopy *ret = get(root);
        ret->left = l;
        ret->right = r;
        return ret;
    }
    unordered_map<Node *, NodeCopy *> mm;
    NodeCopy *get(Node *node) {
        if (node == nullptr) return nullptr;
        auto f = mm.find(node);
        if (f != mm.end()) return f->second;
        NodeCopy *dup = new NodeCopy(node->val);
        mm[node] = dup;
        return dup;
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


