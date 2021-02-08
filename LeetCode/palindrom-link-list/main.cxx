/*
 * Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>


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


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head) {
            return true;
        }

        if (!head->next) {
            return true;
        }
        ListNode *fast = head, *slow = head;
        ListNode *tmp;
        ListNode *prev = nullptr;
        ListNode *next = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = next;
            next = next->next;

            slow = tmp;
            slow->next = prev;
            prev = slow;
        }

        if (fast) {
            next = next->next;
        }


        while (next && slow->val == next->val) {
            slow = slow->next;
            next = next->next;
        }

        return slow == nullptr && next == nullptr;
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

struct T {
    vector<int> nums;
    bool expect;
};
TEST(Solution, isPalindrome) {
    Solution solution;
    T ts[] = {
            {
                    {{1, 2, 3, 4, 3, 2, 1}},
                    true,
            },


            {
                    {{1, 2, 3, 3, 2, 1}},
                    true,
            },

            {
                    {{2, 3, 3, 3, 2, 1}},
                    false,
            },


            {
                    {{1}},
                    true,
            },
            {
                    {{1, 1}},
                    true,
            },
            {
                    {{1, 2, 1}},
                    true,
            },
    };
    ListNode *pNode;
    for (int i = 0; i < sizeof(ts) / sizeof(T); i++) {
        cout << "checking " << i + 1 << endl;
        T t = ts[i];
        pNode = gen(t.nums);
        bool result = solution.isPalindrome(pNode);

        ASSERT_EQ(result, t.expect);
    }

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


