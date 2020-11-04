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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *first = head, *last = head;
        ListNode *now = last->next;

        while (now) {
            if (now->val >= last->val) {
                last = last->next;
            } else { // 1 2 3 5 6 4 7 8
                last->next = last->next->next;
                now->next = nullptr;
                first = insert(first, now);
            }
            now = last->next;
        }
        return first;
    }

private:
    ListNode *insert(ListNode *&first, ListNode *&now) {
        if (now->val < first->val) {
            now->next = first;
            return now;
        }
        ListNode *tmp = first;
        ListNode *tmpLast = nullptr;
        while (tmp) {
            if (now->val < tmp->val) {
                tmpLast->next = now;
                now->next = tmp;
                break;
            }
            tmpLast = tmp;
            tmp = tmp->next;
        }
        return first;
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


