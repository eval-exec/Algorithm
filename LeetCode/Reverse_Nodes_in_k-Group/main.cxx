#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Reverse Nodes in k-Group

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
  ListNode *reverseKGroup(ListNode *head, int k) {
	if (!head) return nullptr;
	if (k == 1) return head;

	int i = 0;
	ListNode *tail = head;
	while (tail) {
	  i++;
	  if (i == k) break;
	  tail = tail->next;
	}
	if (i < k) return head;

	auto *nn = tail->next;
	ListNode *last = nullptr;
	ListNode *cur = head;
	int ki = 0;
	while (ki < k) {
	  ListNode *tmp = cur->next;
	  cur->next = last;
	  last = cur;
	  cur = tmp;
	  ki++;
	}
	head->next = reverseKGroup(nn, k);
	return tail;
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


