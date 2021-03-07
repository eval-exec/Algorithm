#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class MyHashMap {
  public:
    class KV {
      public:
        int key;
        int value;
        KV *next;

        KV(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };
    vector<KV *> map;
    int hash(int k) {
        return k % 10000;
    }
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(10000);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto v = map[hash(key)];
        if (v == nullptr) {
            map[hash(key)] = new KV(key, value);
        } else {
            KV *tail = nullptr;
            while (v) {
                if (v->key == key) {
                    v->value = value;
                    return;
                }
                tail = v;
                v = v->next;
            }
            tail->next = new KV(key, value);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto v = map[hash(key)];
        if (v == nullptr) {
            return -1;
        } else {
            while (v) {
                if (v->key == key) return v->value;
                v = v->next;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto v = map[hash(key)];
        if (v == nullptr) {
            return;
        }
        if (v->key == key) {
            map[hash(key)] = v->next;
            v->next = nullptr;
            delete v;
            return;
        }

        while (v && v->next) {
            if (v->next->key == key) {
                auto tmp = v->next;
                v->next = v->next->next;
                tmp->next = nullptr;

                delete tmp;
                return;
            }
            v = v->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */



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


