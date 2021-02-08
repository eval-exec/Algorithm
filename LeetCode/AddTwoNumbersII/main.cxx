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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto calLen = [](ListNode *l) {
            int len = 0;
            while (l) {
                len++;
                l = l->next;
            }
            return len;
        };

        int len1 = calLen(l1);
        int len2 = calLen(l2);
        if (len1 == 0) {
            return l2;
        } else if (len2 == 0) {
            return l2;
        }
        int n = abs(len1 - len2);
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (n > 0) {
            head = new ListNode(0, head);
            if (!tail) {
                tail = head;
            }
            n--;
        }

        if (len1 > len2) {
            tail->next = l2;
            l2 = head;
        } else if (len1 < len2) {
            tail->next = l1;
            l1 = head;
        }
        ListNode *ret = cal(l1, l2);
        if (ret->val == 0) {
            ret = ret->next;
        }
        return ret;
    }

private:
    ListNode *cal(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return nullptr;
        }
        ListNode *ho = cal(l1->next, l2->next);

        int sum = l1->val + l2->val;
        if (ho) {
            sum += ho->val;
        }
        int cc = 0;
        if (sum >= 10) {
            cc = 1;
            sum -= 10;
        }

        if (ho) {
            ho->val = sum;
        } else {
            ho = new ListNode(sum);
        }
        return new ListNode(cc, ho);
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


