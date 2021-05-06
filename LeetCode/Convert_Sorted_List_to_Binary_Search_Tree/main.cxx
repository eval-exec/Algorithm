#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Convert Sorted List to Binary Search Tree

*/
/**
 * Definition for singly-linked list.
 */
/**
 * Definition for a binary tree node.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  private:
    vector<int> nums;
  public:
    TreeNode *sortedListToBST(ListNode *head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return proc(0, nums.size() - 1);
    }
    TreeNode *proc(int start, int end) {
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        if (start > end) {
            return nullptr;
        }
        int len = end - start + 1;

        int mid = (end + start) / 2;
        if (len % 2 == 1) {
            mid++;
        }
        return new TreeNode(nums[mid], proc(start, mid - 1), proc(mid + 1, end));
    }
};

//// END
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


