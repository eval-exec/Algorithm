
/*
 *
Constraints:

The number of the nodes in the list is in the range [0, 104].

-105 <= Node.val <= 105

pos is -1 or a valid index in the linked-list.


Given a linked list,

return the node where the cycle begins.

If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally,

pos is used to denote the index of the node that tail's next pointer is connected to.

Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?


 */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return nullptr;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (fast && fast->next) {
            if (fast == slow) {
                ListNode *walker = head;
                while (walker != slow) {
                    walker = walker->next;
                    slow = slow->next;
                }
                return slow;
            }
            fast = fast->next->next;
            slow = slow->next;


        }

        return nullptr;


    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


