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
        ListNode* swapNodes(ListNode* head, int k) {
            auto tmp = head;
            int len = 0;
            while(tmp){
                tmp = tmp->next;
                len++;
            }
            ListNode* n1 = nullptr;
            ListNode* n2 = nullptr;
            tmp = head;
            int n = 0;
            while(tmp){
                n++;
                if (n == k) n1 = tmp;
                if (n + k == len + 1) n2 = tmp;
                if (n1 && n2) break;
                tmp = tmp->next;
            }
            swap(n1->val,n2->val);
            return head;
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


