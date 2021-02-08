
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};


class Solution {
public:
    Node *flatten(Node *head) {
        Node *headO = head;
        Node *defer = nullptr;
        while (head) {
            if (head->child) {
                if (head->next) {
                    head->next->child = defer;
                    defer = head->next;

                    head->next = head->child;
                    head->child->prev = head;
                    head->child = nullptr;
                } else {
                    head->next = head->child;
                    head->child->prev = head;
                    head->child = nullptr;
                }


            }
            if (!head->next && defer) {
                cout << head->val << "," << defer->val << endl;
                head->next = defer;
                defer->prev = head;

                defer = defer->child;
                head->next->child = nullptr;
            }
            head = head->next;
        }
        return headO;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


