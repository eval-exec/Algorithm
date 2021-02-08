
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for singly-linked list.
 *
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) {
            return head;
        }
        int count = 0;
        ListNode *tmp = head;
        ListNode *tail = nullptr;
        while (tmp) {
            count++;
            if (!tmp->next) {
                tail = tmp;
            }
            tmp = tmp->next;
        }
        k %= count;

        if (k == 0) {
            return head;
        }

        tmp = head;
        ListNode *slow = tmp;
        while (tmp && tmp->next) {
            tmp = tmp->next;
            if (k <= 0) {
                slow = slow->next;
            } else {
                k--;
            }
        }

        ListNode *nextHead = slow->next;
        slow->next = nullptr;
        tail->next = head;
        return nextHead;
    };
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
    ListNode *in;
    int k;
    ListNode *out;
};

TEST(Solution, rotate) {
    T ts[] = {
            {
                    gen({1, 2, 3, 4}),
                    1,
                    gen({4, 1, 2, 3}),
            },
            {
                    gen({1, 2, 3, 4}),
                    5,
                    gen({4, 1, 2, 3}),
            },
            {
                    gen({1, 2, 3, 4}),
                    4,
                    gen({1, 2, 3, 4}),
            },
            {
                    gen({1}),
                    1,
                    gen({1}),
            },
            {
                    gen({1}),
                    2,
                    gen({1}),
            },
            {
                    gen({}),
                    1,
                    gen({}),
            },
    };

    Solution solution;
    for (T t : ts) {
        cout << "checking..." << endl;
        print((t.in));
        ListNode *result = solution.rotateRight(t.in, t.k);
        print(result);
        print(t.out);
        cout << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


