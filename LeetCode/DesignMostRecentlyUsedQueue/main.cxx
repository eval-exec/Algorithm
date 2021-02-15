#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class MRUQueue {
  public:
    MRUQueue(int n) {
        int i = 1;
        while (i <= n) {
            tail->next = new Node(i);
            tail = tail->next;
            i++;
        }
    }

    int fetch(int k) {
        int i = 0;
        Node *now = head;
        while (true) {
            if (i == k - 1) {
                Node *tmp = now->next;
                if (tmp->next != nullptr) {
                    now->next = now->next->next;
                    tail->next = tmp;
                    tmp->next = nullptr;
                    tail = tail->next;
                }
                return tmp->val;
            }
            i++;
            now = now->next;
        }
    }
  private:
    class Node {
      public:
        int val;
        Node *next;
        Node(int n) : val(n), next(nullptr) {};
    };
    Node *head = new Node(-1);
    Node *tail = head;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */



struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


