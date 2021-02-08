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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 2){
            ListNode* one = lists[0];
            ListNode* two = lists[1];
            if (one == nullptr) return two;
            if (two == nullptr) return one;
            ListNode* head ;
            if (two->val < one->val){
                head =  two;
                two = two->next;
            }else{
                head = one;
                one = one->next;
            }
            ListNode* tmp = head;
            while(one != nullptr && two != nullptr){
                if (one->val < two->val){
                    tmp->next = one;
                    one = one->next;
                }else{
                    tmp->next = two;
                    two = two->next;
                }
                tmp=tmp->next;
            }
            if (one != nullptr){
                tmp->next = one;
            }else if (two != nullptr){
                tmp->next = two;
            }
            return head;
        }
        int len = lists.size();
        vector<ListNode*> left(lists.begin(),lists.begin()+len/2);
        vector<ListNode*> right(lists.begin()+len/2,lists.end());
        ListNode* l = mergeKLists(left);
        ListNode* r = mergeKLists(right);
        vector<ListNode*> ns = {l,r};
        return mergeKLists(ns);
    }
};


struct T{

};

TEST(Solution,test){
    T ts[] = {
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


