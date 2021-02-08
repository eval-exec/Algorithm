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



struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *sentinel = new ListNode(val + 1, head);
        ListNode *prev = sentinel;
        head = sentinel;
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
            } else {
                prev = head;
            }
            head = head->next;
        }
        return sentinel->next;
    }
};


ListNode *gen(vector<int> vs) {
    int len = vs.size();
    ListNode *right = nullptr;
    for (int i = len - 1; i >= 0; i--) {
        ListNode *tmp = new ListNode(vs[i]);
        tmp->next = right;
        right = tmp;
    }
    return right;
}

void print(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

struct T {
    vector<int> nums;
    int target;
};

TEST(Solution, removeElements) {
    Solution solution;
    ListNode *pNode;
    ListNode *pRet;

    T ts[] = {
            {
                    {{1, 2, 3, 3, 4}},
                    3
            },
            {
                    {{1, 2}},
                    1
            },
            {
                    {{1, 2}},
                    2
            }
    };

    for (T t: ts) {
        pNode = gen(t.nums);
        print(pNode);
        cout << '\b]\n' << " " << "remove " << t.target << " " << endl;
        pRet = solution.removeElements(pNode, t.target);
        print(pRet);

    }


}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
