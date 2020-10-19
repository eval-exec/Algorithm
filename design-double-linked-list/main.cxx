/*
 *
 * design doubly linked list:
 *
 *
 */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        _list = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        listT *l = _list;
        while (l) {
            if (i == index) {
                return l->val;
            }
            l = l->next;
            i++;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        listT *l = new listT(val);
        if (!_list) {
            _list = l;
            return;
        }
        l->next = _list;
        _list->prev = l;
        _list = l;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        listT *newL = new listT(val);
        if (!_list) {
            return;
        }
        listT *l = _list;
        while (l->next) {
            l = l->next;
        }
        l->next = newL;
        newL->prev = l;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        int i = 1;
        listT *l = _list->next;
        while (l) {
            if (index == i) {
                listT *newL = new listT(val);
                l->prev->next = newL;
                newL->prev = l->prev;
                newL->next = l;
                l->prev = newL;
                return;
            }
            i++;
            l = l->next;
        }
        if (i == index) {
            addAtTail(val);
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        listT *l = _list;
        if (index == 0) {
            _list = _list->next;
            _list->prev = nullptr;

            l->next = nullptr;
            l->prev = nullptr;
            free(l);
            return;
        }

        int i = 0;
        while (l->next) {
            if (i == index) {
                l->prev->next = l->next;
                l->next->prev->prev = l->prev;

                l->prev = nullptr;
                l->next = nullptr;
                free(l);
                return;
            }

            l = l->next;
            i++;
        }


    }


private:
    struct listT {
        int val;
        listT *next;
        listT *prev;

        listT(int v) {
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    listT *_list;

};

void print(MyLinkedList &list) {
    int i = 0;
    int ret = -1;
    while (true) {
        ret = list.get(i);
        if (ret == -1) {
            break;
        }
        cout << ret << " ";
        i++;
    }
    cout << endl;
}

TEST(MyLinkedList, doublyLinkedList) {
    MyLinkedList myLinkedList;
    int ret = myLinkedList.get(0);
    ASSERT_EQ(ret, -1);

    print(myLinkedList);
    myLinkedList.addAtIndex(0, 1);
    print(myLinkedList);

    myLinkedList.addAtIndex(10, 10);
    print(myLinkedList);
    myLinkedList.addAtIndex(10, 11);
    print(myLinkedList);
    myLinkedList.addAtIndex(10, 12);
    print(myLinkedList);
    myLinkedList.addAtIndex(1, 12);
    print(myLinkedList);
    myLinkedList.addAtIndex(0, 2);
    print(myLinkedList);

    myLinkedList.addAtIndex(1, 3);
    print(myLinkedList);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


