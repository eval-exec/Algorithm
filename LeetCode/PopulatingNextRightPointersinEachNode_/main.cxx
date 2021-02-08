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
        if (!root) return root;
        Node *oroot = root;
        root->next = nullptr;
        conn(root);
        return oroot;
    }

private:
    void conn(Node *leftMost) {
        if (!leftMost) return;
        Node *leftDown;
        if (leftMost->left) {
            leftDown = leftMost->left;
        }

        Node *start = leftMost->left;
        while (leftMost) {
            if (leftMost->left) {
                start->next = leftMost->left;
                start = start->next;
            }
            if (leftMost->right) {
                start->next = leftMost->right;
                start = start->next;
            }
            leftMost = leftMost->next;
        }
        conn(leftDown);
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


