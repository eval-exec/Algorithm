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

    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *even = head;
        ListNode *odd = head->next;
        ListNode *rOdd = odd;

        while (odd != nullptr && odd->next != nullptr) {
            even->next = even->next->next;
            even = even->next;
            odd->next = odd->next->next;
            odd = odd->next;
        }
        // 1.2.3.4.5
        // 1.2.3.4
        even->next = rOdd;
        return head;
    }

    ListNode *oddEvenList1(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *first = head, *firstO = head;
        ListNode *second = head->next, *secondO = head->next;
        if (second == nullptr) {
            return first;
        }

        head = head->next->next;
        uint count = 0;
        while (head != nullptr) {
            if ((count & 1) == 0) {
                first->next = head;
                first = first->next;
            } else {
                second->next = head;
                second = second->next;
            }
            head = head->next;
            count++;
        }
        second->next = nullptr;
        first->next = secondO;
        return firstO;
    }
};

void print(ListNode *list) {
    cout << "print" << endl;
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

ListNode *gen(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode *listp = new ListNode();
    ListNode *listo = listp;
    for (int n:nums) {
        listp->next = new ListNode(n);
        listp = listp->next;
    }
    return listo->next;


}

vector<int> genBigVet(uint n) {
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        x.push_back(i);
    }
    return x;

}

TEST(Solution, addEvenList) {
    Solution solution;

    ListNode *pNode = gen({1, 2, 3, 4, 5});
    ListNode *pret = solution.oddEvenList(pNode);

    print(pret);


    pNode = gen({1, 2, 3, 4, 5, 6});
    pret = solution.oddEvenList(pNode);
    print(pret);


    pNode = gen({1});
    pret = solution.oddEvenList(pNode);
    print(pret);

    pNode = gen({1, 2});
    pret = solution.oddEvenList(pNode);
    print(pret);

    pNode = gen({1, 2, 3});
    pret = solution.oddEvenList(pNode);
    print(pret);


    pNode = gen({});
    pret = solution.oddEvenList(pNode);
    print(pret);


//    pNode = gen(genBigVet(100000));
//    pret = solution.oddEvenList(pNode);
//    print(pret);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


