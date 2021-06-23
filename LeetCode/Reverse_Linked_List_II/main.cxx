#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Reverse Linked List II

*/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* nh = new ListNode();
      nh->next = head;
      ListNode* cur= nh;
      ListNode* lnp = nullptr;
      ListNode* rn = nullptr;
      ListNode* ln = nullptr;
      ListNode* tail = nullptr;
      int count = 0;

      ListNode* last = nullptr;

      while(cur){
	if (count + 1 == left){
	  ln = cur->next;
	  lnp = cur;
	}
	if (count == right){
	  rn = cur;
	  tail = cur->next;
	}
	if (count >= left && count <= right){
	  ListNode* tmp = cur->next;
	  cur->next = last;
	  last = cur;
	  cur = tmp;
	}else{
	  last = cur;
	  cur = cur->next;
	}
	count++;
      }
      lnp->next = rn;
      ln->next = tail;
      return nh->next;
    }
};


//// END
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


