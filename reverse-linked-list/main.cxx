/*
 *


Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL

Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively.

Could you implement both?

 */

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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

ListNode *gen(vector<int> vs) {
    int len = vs.size();
    ListNode *right = nullptr;
    for (int i = len - 1; i >= 0; i--) {
        ListNode *tmp = new ListNode(vs[i]);
        tmp->next = right;
        right = tmp;
    }
    return right;
}

void print(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

TEST(Soluton, reversr) {
    Solution solution;

    ListNode *pNode = gen({1, 2, 3, 4, 5, 6, 7, 8});
    print(pNode);
    ListNode *pret = solution.reverseList(pNode);
    print(pret);


    pNode = gen({1});
    print(pNode);
    pret = solution.reverseList(pNode);
    print(pret);


    pNode = gen({});
    print(pNode);
    pret = solution.reverseList(pNode);
    print(pret);


    pNode = gen({1,2,3});
    print(pNode);
    pret = solution.reverseList(pNode);
    print(pret);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


