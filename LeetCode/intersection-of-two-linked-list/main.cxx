
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head, ListNode *headB) {

        cout << head << endl;
        if (!head) {
            return nullptr;
        }


        if (!headB) {

            return nullptr;
        }
        ListNode *tmp = head;
        while (head->next) {
            head = head->next;
        }
        ListNode *tail = head;
        head->next = headB;
        head = tmp;


        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (fast && fast->next) {
            if (fast == slow) {
                ListNode *walker = head;
                while (walker != slow) {
                    walker = walker->next;
                    slow = slow->next;
                }

                tail->next = nullptr;

                return slow;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        tail->next = nullptr;

        return nullptr;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


