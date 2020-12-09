#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
  private:
    stack<TreeNode *> st;
  public:
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;

        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }

    int next() {
        TreeNode *top = st.top();
        st.pop();
        if (top->right) {
            TreeNode *tmp = top->right;
            while (tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        return top->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


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


