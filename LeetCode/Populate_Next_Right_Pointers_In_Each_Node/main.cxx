
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        if (!root->left) {
            return root;
        }
        root->left->next = root->right;
        con(root);
        return root;
    }

    Node *con(Node *p) {
        if (!p) {
            return nullptr;
        }
        if (p->left) {
            p->left->next = p->right;
        } else {
            return p;
        }
        if (p->next) {
            p->right->next = p->next->left;
        }
        con(p->left);
        con(p->right);
        return nullptr;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


