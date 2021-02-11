#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
};
*/

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        Node *cur = head;
        while (cur) {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while (cur) {
            Node *r = cur->random;
            if (r != nullptr) {
                cur->next->random = r->next;
            }
            cur = cur->next->next;
        }

        Node *RET = head->next;
        Node *ret = RET;
        cur = head;
        // 1 [1] 2 [2] 3 [3]
        while (cur) {
            cur->next = cur->next->next;
            cur = cur->next;

            if (ret->next) {
                ret->next = ret->next->next;
                ret = ret->next;
            }
        }
        return RET;
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


