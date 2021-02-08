
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
 * Given an array nums and a value val,
 * remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array,
 you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed.
 It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2,
 with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5,
 with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.

Clarification
 */


class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums.at(i) == val) {
                len--;
                nums.erase(nums.begin() + i);
                i--;
            }

        }
        return len;
    }
};

struct testcase {
    int id;
    vector<int> nums;
    int val;
    int expect;
};

void print(vector<int> vs) {
    for (int v: vs) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, removeElement) {
    testcase ts[] = {
            {
                    1,
                    {
                            {3, 2, 2, 3}
                    },
                    3,
                    2,
            },

            {
                    2,
                    {
                            {0, 1, 2, 2, 3, 0, 4, 2}
                    },
                    2,
                    5,
            }
    };

    Solution solution;
    for (testcase t: ts) {

        printf("checking %d\n", t.id);
        print(t.nums);
        int c = solution.removeElement(t.nums, t.val);
        print(t.nums);
        ASSERT_EQ(c, t.expect);
    }
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


/*
 * class Solution
{
public:

int removeElement(vector<int>& n, int val)
{
    n.erase(std::remove(n.begin(), n.end(), val), n.end());

    return n.size();
}
};


 */

