#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for singly-linked list.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> vs(lists.size(), 0);
        ListNode *head = next(lists);
        if (head == nullptr) return nullptr;
        ListNode *o_head = head;

        while (true) {
            head->next = next(lists);
            if (head->next == nullptr) {
                break;
            }
            head = head->next;
        }

        return o_head;
    }

private:

    ListNode *next(vector<ListNode *> &lists) {
        int index = 0;
        ListNode *least = nullptr;
        int li = 0;
        for (index = 0; index < lists.size(); index++) {
            if (lists[index] == nullptr) {
                continue;
            }
            if (least == nullptr) {
                least = lists[index];
                li = index;
            } else {
                if (lists[index]->val < least->val) {
                    least = lists[index];
                    li = index;
                }
            }
        }
        if (least == nullptr) {
            return nullptr;
        }
        lists[li] = lists[li]->next;
        return least;
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


