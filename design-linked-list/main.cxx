
/*
 *
 * Design your implementation of the linked list.
 * You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next.val is the value of the current node,
 and next is a pointer/reference to the next node.
If you want to use the doubly linked list,
 you will need one more attribute prev to indicate the previous node in the linked list.
 Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid,
 return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion,
 the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list,
 if the index is valid.


 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        list = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (!list) {
            return -1;
        }
        int i = 0;
        listT *head = list;
        while (head) {
            if (index == i) {
                return head->val;
            }
            i++;
            head = head->next;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!list) {
            list = new listT(val);
            return;
        }

        listT *head = new listT(val);
        head->next = list;
        list = head;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!list) {
            list = new listT(val);
            return;
        }

        listT *head = list;
        while (head->next) {
            head = head->next;
        }

        head->next = new listT(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (!list) {
            list = new listT(val);
            return;
        }

        if (index == 0) {
            listT *tmp = new listT(val);
            tmp->next = list;
            list = tmp;
            return;
        }

        listT *head = list;
        listT *prev = head;
        head = head->next;

        int i = 1;
        while (head) {
            if (i == index) {
                listT *tmp = new listT(val);
                prev->next = tmp;
                tmp->next = head;
                return;
            }
            prev = head;
            head = head->next;
            i++;
        }
        if ( i == index){
            listT *t = new listT(val);
            prev->next = t;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (!list) {
            return;
        }
        if (index == 0) {
            list = list->next;
            return;
        }

        listT *prev = list;
        listT *head = list->next;
        int i = 1;
        while (head) {
            if (index == i) {
                prev->next = head->next;
                return;
            }
            prev = head;
            head = head->next;
            i++;
        }

    }


private:
    struct listT {
        int val;
        listT *next;

        listT(int v) {
            val = v;
            next = nullptr;
        }
    };

    listT *list;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
void print(MyLinkedList &list) {
    cout << "printing..." << endl;
    if (list.get(0) == -1) {
        cout << "?" << endl;
        return;
    }
    int i = 0;
    while (1) {
        int got = list.get(i);
        if (got == -1) {
            cout << endl;
            return;
        }
        cout << got << " ";
        i++;
    }
}

TEST(Solution, linkList) {
    MyLinkedList obj;
    int got = obj.get(1);
    cout << got << endl;
    obj.addAtTail(3);
    got = obj.get(0);
    cout << got << endl;

    print(obj);
    obj.addAtHead(1);
    print(obj);


    obj.addAtIndex(1, 10);
    print(obj);

    obj.addAtIndex(2, 11);
    print(obj);

    obj.addAtIndex(0, 15);
    print(obj);

    obj.deleteAtIndex(0);
    print(obj);


    obj.deleteAtIndex(1);
    print(obj);

    obj.deleteAtIndex(2);
    print(obj);


    obj.deleteAtIndex(1);
    print(obj);

    obj.deleteAtIndex(0);
    print(obj);

}

TEST(test2, test2) {
    MyLinkedList obj;
    /*
     *
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead",
     "addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],
     [4],[4],[4],[5,0],[6]]

     */

    // 127
    obj.addAtHead(7);
    obj.addAtHead(2);
    obj.addAtHead(1);
    obj.addAtIndex(3, 0);
    obj.deleteAtIndex(2);
    obj.addAtHead(6);
    obj.addAtTail(4);
    int i = obj.get(4);
    cout << "got"<< i<< endl;
    obj.addAtHead(4);
    obj.addAtIndex(5, 0);
    obj.addAtHead(6);
    print(obj);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


