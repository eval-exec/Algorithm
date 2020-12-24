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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * root = new ListNode(0,head);
        ListNode *tmp = root;
        while(tmp&&tmp->next && tmp->next->next){
            // f, s, thrd, forth, fifth
            ListNode *first = tmp->next;
            ListNode *second = tmp->next->next;
            ListNode *third = tmp->next->next->next;
            tmp->next=second;
            second->next=first;
            first->next=third;
            tmp = first;
        }
        return root->next;

    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


