#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    class Node {
      public:
        int value;
        Node *next;
        Node(int v) {
            value = v;
            next = nullptr;
        }
    };

    int findTheWinner(int n, int k) {
        auto head = new Node(1);
        auto tmp = head;
        for (int i = 2; i <= n; i++) {
            tmp->next = new Node(i);
            tmp = tmp->next;
        }
        tmp->next = head;
        auto prev = tmp;
        while (head->next != head) {
            int nk = k;
            while (nk > 1) {
                nk--;
                prev = head;
                head = head->next;
            }
            prev->next = head->next;
            head = head->next;
        }
        return head->value;
    }
};

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


