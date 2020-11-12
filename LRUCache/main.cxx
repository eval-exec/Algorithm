#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/*
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
 Otherwise, add the key-value pair to the cache.
 If the number of keys exceeds the capacity from this operation,
 evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        auto p = _mm.find(key);
        if (p == _mm.end()) {
            return NOTFOUND;
        }
        int ret = p->second->value;
        if (p->second == tail) {
            return ret;
        }
        if (p->second == head) {
            node *ohead = head;
            head = head->next;
            head->prev = nullptr;
            ohead->next = nullptr;
            tail->next = ohead;
            ohead->prev = tail;
            tail = ohead;
        } else {
            p->second->prev->next = p->second->next;
            p->second->next->prev = p->second->prev;

            p->second->next = nullptr;
            p->second->prev = tail;
            tail->next = p->second;
            tail = p->second;
        }


        return ret;
    }

    void put(int key, int value) {
        node *tmp = new node(key, value);
        if (!head) {
            _mm[key] = tmp;
            head = tmp;
            tail = tmp;
            head->next = tail;
            tail->prev = head;
            return;
        }
        auto p = _mm.find(key);
        if (p == _mm.end()) {
            _mm[key] = tmp;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
            if (_mm.size() > _cap) {
                int needDelete = head->key;
                node *thead = head;
                head = head->next;
                head->prev = nullptr;
                thead->next = nullptr;
                delete thead;
                _mm.erase(needDelete);
            }
            return;
        }
        p->second->value = value;

        if (_mm.size() == 1 || p->second == tail) {
            return;
        }

        if (p->second == head) {
            node *ohead = head;
            head = head->next;
            head->prev = nullptr;

            tail->next = ohead;
            ohead->prev = tail;
            ohead->next = nullptr;
            tail = ohead;
        } else {
            p->second->prev->next = p->second->next;
            p->second->next->prev = p->second->prev;

            p->second->next = nullptr;
            p->second->prev = tail;
            tail->next = p->second;
            tail = p->second;
        }

    }

private:

    struct node {
        int key;
        int value;
        node *prev;
        node *next;

        node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {};
    };


    const int NOTFOUND = -1;
    int _cap;

    node *head = nullptr;
    node *tail = nullptr;

    map<int, node *> _mm;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


struct T {

};

/*
 *["LRUCache","put","put","get","put","put","get"]
[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
 */
TEST(Solution, test) {
    LRUCache cache = LRUCache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(2));
    cache.put(1, 1);
    cache.put(4, 1);
    printf("%d\n", cache.get(2));
    printf("%d\n", cache.get(4));
    cache.put(4, 8);
    printf("%d\n", cache.get(4));
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


