/*
 *
 *
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast && fast->next) {
            if (fast == slow) {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};

ListNode *gen(vector<int> nums, int pos) {
    int len = nums.size();
    ListNode *tmp = new ListNode(nums[len - 1]);
    ListNode *tail = tmp;
    for (int i = len - 2; i >= 0; i--) {
        ListNode *x = new ListNode(nums[i]);
        x->next = tmp;
        tmp = x;
        if (i == pos) {
            tail->next = x;
        }
    }
    return tmp;
}

void print(ListNode *node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}


void print(ListNode *node, int n) {
    while (node && n >= 0) {
        cout << node->val << " ";
        node = node->next;
        n--;
    }
    cout << endl;
}

TEST(Solution, hasCyle) {
    Solution solution;

    ListNode *pNode = gen({1}, -1);
    bool b = solution.hasCycle(pNode);
    cout << b << endl;
    if (b) {
        print(pNode, 10);
    } else {
        print(pNode);
    }

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


