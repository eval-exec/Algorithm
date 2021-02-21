#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



/*
// Definition for a Node.
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == nullptr) return nullptr;
        Node* dup = new Node(root->val);
        for (auto child: root->children){
            dup->children.push_back(cloneTree(child));
        }
        return dup;
    }
};


struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


