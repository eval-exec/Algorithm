
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    out << "{";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "}";
    return out;
}


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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        vector<int> ret;
        ret.push_back(root->val);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }


    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        vector<int> ret;
        ret.insert(ret.end(), left.begin(), left.end());
        ret.push_back(root->val);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }


    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        vector<int> ret;
        ret.insert(ret.end(), left.begin(), left.end());
        ret.push_back(root->val);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        int level = 1;
        while (true) {
            vector<int> golds = dig(root, level);
            level++;
            if (golds.empty()) {
                break;
            }
            if (golds.size() > 10) {
                break;
            }
            ret.push_back(golds);
        }

        return ret;
    }

    vector<int> dig(TreeNode *node, int level) {
        if (!node) {
            return {};
        }
        if (level == 1) {
            return {node->val};
        }

        vector<int> left = dig(node->left, level - 1);
        vector<int> right = dig(node->right, level - 1);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }

};

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root){
            return res;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> level;
            for (int i = 0; i < size; i++){
                TreeNode* front = queue.front();
                level.push_back(front->val);
                queue.pop();

                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);
            }
            res.push_back(level);
        }

        return res;
    }
};

int get(vector<int> nodes, int i) {
    if (nodes.size() <= i) {
        return -1;
    }
    return nodes[i];
}

/*
 *
 * 0
 * 1,2
 * 3,4  5,6
 * 7,8, 9,10 , 11,12 ,  13,14
 * 14,16 17,18,   19,20
 */

#include <iterator> // needed for std::ostram_iterator

TreeNode *_gen(vector<int> &nodes, int i) {
    int val = get(nodes, i);
    if (val < 0) {
        return nullptr;
    }
    TreeNode *l = _gen(nodes, 2 * i + 1);
    TreeNode *r = _gen(nodes, 2 * i + 2);

    return new TreeNode(val, l, r);
}

TreeNode *gen(vector<int> &nodes) {
    return _gen(nodes, 0);
}

struct T {
    vector<int> nodes;
};

TEST(Solution, preOrderTravesal) {
    Solution solution;

    T ts[] = {
            {
                    {{1, 2,  3,  4,  5,  6}}
            },
            {
                    {{1, -1, 2}}
            },
            {
                    {{3, 9,  20, -1, -1, 15, 7}}
            },
            {
                    {{}}
            },
            {
                    {{1}}
            },
    };

    for (T t: ts) {
        cout << "checking ..." << endl;
        cout << t.nodes << endl;
        vector<vector<int>> stones = solution.levelOrder(gen(t.nodes));
        cout << stones << endl;
        cout << endl;
    }

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


