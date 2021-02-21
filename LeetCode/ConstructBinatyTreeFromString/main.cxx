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
class Solution {
  public:
    TreeNode *str2tree(string s) {
        if (s.empty()) return nullptr;
        return conv(s, 0, s.size());
    }
    TreeNode *conv(const string &s, int left, int len) {
        if (len <= 0) return nullptr;
        if (s[left] == '(') return conv(s, left + 1, len - 2);
        int i = left;
        while (i < left + len && s[i] >= '0' && s[i] <= '9' || s[i] == '-') {
            i++;
        }
        int start = i;

        string sub = s.substr(left, i - left);

        TreeNode *ret = new TreeNode(stoi(sub));
        if (i == left + len) return ret;

        int mid = 0;
        {

            int count = 0;
            for (; i < left + len; i++) {
                if (s[i] == ')') {
                    count--;
                } else if (s[i] == '(') {
                    count++;
                }
                if (count == 0) {
                    mid = i;
                    break;
                }
            }
        }
        ret->left = conv(s, start, mid - start + 1);
        ret->right = conv(s, mid + 1, left + len - mid - 1);
        return ret;
    }
};

struct T {
    string src;

};

TEST(Solution, test) {
    T ts[] = {
        {
            "4(2(3)(1))(6(5))",

        },

    };

    for (T t : ts) {
        Solution solution;
        solution.str2tree(t.src);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


