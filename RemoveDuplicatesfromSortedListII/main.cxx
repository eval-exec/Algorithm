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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* ret = new ListNode();
        ListNode* tmp = ret;
        while(head){
            int val = head->val;
            if (head->next && head->next->val == val){
                while(head && head->val == val){
                    head = head->next;
                }
            }else{
                tmp->next = head;
                head = head->next;
                tmp= tmp->next;
                tmp->next = nullptr;
            }
        }
        return ret->next;
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


