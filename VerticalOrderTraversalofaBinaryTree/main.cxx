#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        travel(root, 0, 0);
        vector<vector<int>> rets;
        for (auto &m : mm) {
            vector<int> ret;
            auto &depth = m.second;
            for (auto &dh : depth) {
                for (int v : dh.second) {
                    ret.push_back(v);
                }
            }
            rets.push_back(ret);
        }
        return rets;
    }
  private:
    map<int, map<int, set<int>>> mm;
    void travel(TreeNode *root, int depth, int index) {
        if (root == nullptr)return;
        update(index, depth, root->val);
        travel(root->left, depth + 1, index - 1);
        travel(root->right, depth + 1, index + 1);
    }
    void update(int index, int depth, int value) {
        mm[index][depth].insert(value);
    }
};

//vector<vector<pair<int, int>>> left;
//vector<vector<pair<int, int>>> mright;
//        if (index >= 0) {
//            if (index >= mright.size()) {
//                mright.resize(index + 1);
//            }
//            mright[index].push_back(make_pair(depth, value));
//        } else {
//            index++;
//            index = -index;
//            if (index >= left.size()) {
//                left.resize(index + 1);
//            }
//            left[index].push_back(make_pair(depth, value));
//        }

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


