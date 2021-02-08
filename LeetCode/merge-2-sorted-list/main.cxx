
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode;
        ListNode *headO = head;
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }
        return headO->next;
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

TEST(Solution, mergeLinkList) {
    Solution solution;
    ListNode *l1;
    ListNode *l2;
    ListNode *pNode;
    l1 = gen({1, 3, 5, 7});
    l2 = gen({2, 4, 6, 8});


    pNode = solution.mergeTwoLists(l1, l2);
    print(pNode);
    l1 = gen({3, 5, 7});
    l2 = gen({1, 2, 9});

    pNode = solution.mergeTwoLists(l1, l2);
    print(pNode);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


