#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Remove Nth Node From End of List

*/
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        if (n == len){
            auto ret = head->next;
            head->next = nullptr;
            delete head;
            return ret;
        }
        int i = 1;
        tmp = head;
        while(i + n < len){
            tmp = tmp->next;
            i++;
        }
        auto rm = tmp->next;
        tmp->next = rm->next;
        rm->next = nullptr;
        delete rm;
        return head;
    }
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


