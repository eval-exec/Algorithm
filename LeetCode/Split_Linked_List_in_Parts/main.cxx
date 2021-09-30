#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

//// START
/*
## Split Linked List in Parts

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
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int length = 0;
    ListNode *tmp = head;
    while (tmp) {
      tmp = tmp->next;
      length++;
    }
    int n = length / k;
    int remain = length % k;
    if (n == 0) {
      n = 1;
      remain = 0;
    }

    vector<ListNode *> rets;
    tmp = head;
    int count = 0;
    ListNode* last = nullptr;
    while (tmp) {
      if (count == n + (remain > 0 ? 1 : 0)) {
	if (!rets.empty()) {
	  last->next = nullptr;
	}
	remain--;
	rets.push_back(tmp);
	count = 0;
      } else {
	if (!rets.empty()) {
	  last->next = tmp;
	} else {
	  rets.push_back(tmp);
	}
      }
      count++;
      last = tmp;
      tmp = tmp->next;
    }
    while (rets.size() < k) {
      rets.push_back({});
    }
    return rets;
  }
};

//// END
struct T {};

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
