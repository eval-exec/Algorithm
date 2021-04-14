#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return nullptr;
        auto newhead = new ListNode(-201);
        newhead->next = head;
        auto tmp = newhead;
        while (tmp) {
            if (tmp->next && tmp->next->val >= x) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp) {
            auto cur = tmp;
            while (cur->next) {
                if (cur->next->val < x) {
                    if (tmp != cur) {
                        auto rem = cur->next;
                        cur->next = cur->next->next;
                        rem->next = tmp->next;
                        tmp->next = rem;
                        tmp = tmp->next;
                        continue;
                    }
                }
                cur = cur->next;
            }
        }
        auto ret = newhead->next;
        newhead->next = nullptr;
        delete newhead;
        return ret;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
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


