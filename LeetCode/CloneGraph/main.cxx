#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
*/

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;
        Node *h1 = new Node(0, {node});
        Node *h2 = new Node(0);
        queue<Node *> q1, q2;
        q1.push(h1);
        q2.push(h2);
        unordered_map<Node *, bool> visited;
        unordered_map<Node *, Node *> mm;

        while (!q1.empty()) {
            int qlen = q1.size();
            while (qlen > 0) {
                qlen--;

                auto now1 = q1.front();
                q1.pop();

                auto now2 = q2.front();
                q2.pop();

                if (visited[now1]) {
                    continue;
                } else {
                    visited[now1] = true;
                }

                for (auto nx : now1->neighbors) {
                    q1.push(nx);

                    auto f = mm.find(nx);
                    Node *nxdp;
                    if (f == mm.end()) {
                        nxdp = new Node(nx->val);
                        mm[nx] = nxdp;
                    } else {
                        nxdp = f->second;
                    }
                    q2.push(nxdp);
                    now2->neighbors.push_back(nxdp);
                }
            }
        }
        if (h2->neighbors.empty()) return nullptr;
        Node *ret = h2->neighbors[0];
        h2->neighbors = {};
        h1->neighbors = {};
        return ret;
    }
};

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


