
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *left = head;
        ListNode *right = head;
        for (int i = n; i > 1; i--) {
            if (!right) {
                return nullptr;
            }
            right = right->next;
        }

        if (!right->next) {
            return left->next;
        }

        ListNode *prev = left;
        while (right->next) {
            right = right->next;
            prev = left;
            left = left->next;
        }
        prev->next = left->next;
        return head;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


