
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/



class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


int get(vector<int> nodes, int i) {
    if (nodes.size() <= i) {
        return -1;
    }
    return nodes[i];
}

Node *_gen(vector<int> &nodes, int i) {
    int val = get(nodes, i);
    if (val < 0) {
        return nullptr;
    }
    Node *l = _gen(nodes, 2 * i + 1);
    Node *r = _gen(nodes, 2 * i + 2);

    return new Node(val, l, r, nullptr);
}

Node *gen(vector<int> &nodes) {
    return _gen(nodes, 0);
}

vector<int> dump(Node *root) {
    list<Node *> mm;
    mm.push_back(root);

    vector<int> ret;

    int lastL = 0;
    while (!mm.empty()) {
        int len = mm.size();
        lastL = len;
        bool did = false;
        while (len > 0) {
            Node *f = mm.front();
            mm.pop_front();

            if (!f) {
                ret.push_back(-1);
                len--;
                continue;
            } else {
                ret.push_back(f->val);
                did = true;
            }
            if (f->left) {
                mm.push_back(f->left);
            } else {
                mm.push_back(nullptr);
            }
            if (f->right) {
                mm.push_back(f->right);
            } else {
                mm.push_back(nullptr);
            }
            len--;
        }
        if (!did) {
            ret.erase(ret.end() - lastL, ret.end());
        }
    }
    return ret;
}

struct T {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> nodes;
};

void print(vector<int> ns) {
    cout << "{";
    for (int n: ns) {
        cout << n << " ";
    }
    cout << "}";
    cout << endl;
}

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }
        if (!root->left && !root->right) {
            return root;
        }
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        con(root->right);
        con(root->left);
        return root;
    }

    Node *con(Node *p) {
        if (!p) {
            return nullptr;
        }
        if (!p->left && !p->right) {
            return p;
        }

        Node *l = nullptr;
        Node *r = nullptr;

        if (p->right) {
            l = p->right;
            if (p->left) {
                p->left->next = p->right;
            }
        } else {
            l = p->left;
        }
        r = getNeighbor(p->next);
        if (l && r) {
            l->next = r;
        }

        con(p->right);
        con(p->left);
        return nullptr;

    }

    Node *getNeighbor(Node *p) {
        Node *tmp = p;
        while (tmp) {
            if (!isLeaf(tmp)) {
                if (tmp->left) {
                    return tmp->left;
                }
                return tmp->right;
            }

            tmp = tmp->next;
        }

        return nullptr;

    }

    bool isLeaf(Node *p) {
        return !p->left && !p->right;
    }
};


int main() {
    testing::InitGoogleTest();
    Solution solution;
    vector<int> nodes = {2, 1, 3, 0, 7, 9, 1, 2, -1, 1, 0, -1, -1, 8, 8, -1, -1, -1, -1, 7};
    Node *root = gen(nodes);
    solution.connect(root);

    return RUN_ALL_TESTS();
}


void connect(Node *root) {
    Node *now, *tail, *head;

    now = root;
    head = tail = NULL;
    while (now) {
        if (now->left) {
            if (tail) {
                tail = tail->next = now->left;
            } else {
                head = tail = now->left;
            }
        }
        if (now->right) {
            if (tail) tail = tail->next = now->right;
            else head = tail = now->right;
        }
        if (!(now = now->next)) {
            now = head;
            head = tail = NULL;
        }
    }
}
