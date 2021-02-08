#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
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
        Node *oroot = root;
        while (root) {
            Node *tmp = nullptr;
            Node *prev = nullptr;
            while (root) {
                if (!tmp) {
                    if (root->left) {
                        tmp = root->left;
                        prev = root->left;
                    } else if (root->right) {
                        tmp = root->right;
                        prev = root->right;
                    } else {
                        root = root->next;
                        continue;
                    }
                }
                if (root->left) {
                    prev->next = root->left;
                    prev = prev->next;
                }
                if (root->right) {
                    prev->next = root->right;
                    prev = prev->next;
                }
                prev->next = nullptr;
                root = root->next;
            }
            root = tmp;
        }
        return oroot;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


