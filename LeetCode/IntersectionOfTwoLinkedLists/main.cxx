#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA|| !headB) return nullptr;
        int lena = 0,lenb  = 0;
        ListNode* tmp = headA;
        while(tmp){
            lena++;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            lenb++;
            tmp = tmp->next;
        }
        if (lena > lenb){
            swap(lena,lenb);
            swap(headA,headB);
        }
        int delta = lenb - lena;
        while(delta > 0){
            headB = headB->next;
            delta--;
        }
        while(headA){
            if (headA == headB) return headA;
            headA = headA->next;
            headB= headB->next;
        }
        return nullptr;
    }
};



struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


