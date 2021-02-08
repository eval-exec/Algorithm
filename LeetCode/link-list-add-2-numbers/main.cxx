
/*

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order, and each of their nodes contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
 *
 *
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *head = l1;
        int count = 0;
        int sum = 0;
        ListNode *l1p;
        while (l1 && l2) {
            sum = l1->val + l2->val + count;
            l1->val = sum % 10;
            count = sum / 10;

            l1p = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            l1p->next = l2;
            while (l2) {
                sum = l2->val + count;
                l2->val = sum % 10;
                count = sum / 10;
                l1p = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            while (l1) {
                sum = l1->val + count;
                l1->val = sum % 10;
                count = sum / 10;

                l1p = l1;
                l1 = l1->next;
            }

        }
        if (count > 0) {
            l1p->next = new ListNode(count);
        }
        return head;

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

struct T {
    ListNode *nums1;
    ListNode *nums2;
    ListNode *expect;
};

TEST(Solution, addTwoNumber) {
    T ts[] = {
            {
                    gen({2, 4, 3}),
                    gen({5, 6, 4}),
                    gen({7, 0, 8}),
            },
            {
                    gen({9, 9, 9, 9, 9, 9, 9}),
                    gen({9, 9, 9, 9}),
                    gen({1, 0, 0, 0, 9, 9, 9, 8}),
            }
    };

    Solution solution;
    for (T t: ts) {
        print(t.nums1);
        print(t.nums2);
        ListNode *result = solution.addTwoNumbers(t.nums1, t.nums2);
        print(result);
        print(t.expect);
        while (result) {
            ASSERT_NE(t.expect, nullptr);
            ASSERT_EQ(result->val, t.expect->val);
            result = result->next;
            t.expect = t.expect->next;
        }
        ASSERT_EQ(t.expect, nullptr);
        cout << "ok" << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


