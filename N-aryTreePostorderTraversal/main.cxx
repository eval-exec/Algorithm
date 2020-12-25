#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
*/

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
  public:
    vector<int> postorder(Node *root) {
        stack<Node *> st;
        vector<int> ret;
        st.push(root);
        while (!st.empty()) {
            Node *node = st.top();
            st.pop();
            ret.push_back(root->val);
            for (Node *child:node->children) {
                st.push(child);
            }
        }
        reverse(ret.begin(),ret.end());
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

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


