/*
 * Given a sorted array nums,
 * remove the duplicates in-place such that each element appears only once and returns the new length.
 *

Do not allocate extra space for another array,
 you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2,
 with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5,
 with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.


 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {

        int index = 0;
        int len = nums.size();
        if (len == 0){
            return 0;
        }
        int tmp = nums.at(0);
        int i = 1;
        while (index < len) {
            if (index == 0) {
                index++;
                continue;
            }
            if (nums.at(index) == tmp) {
                index++;
                continue;
            }
            nums.at(i) = nums.at(index);
            tmp = nums.at(index);
            i++;
            index++;
        }
        return i;

    }
};

void print(vector<int> vs) {
    for (int v: vs) {
        cout << v << " ";
    }
    cout << endl;
}

struct T {
    vector<int> nums;
    vector<int> ret;
    int expect;
};
TEST(Solution, removeDuplicates) {
    Solution solution;

    T ts[] = {
            {
                    {{1, 1, 2}},
                    {{1, 2}},
                    2,
            },
            {
                    {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}},
                    {{0, 1, 2, 3, 4}},
                    5
            },
            {
                    {{0}},
                    {{0}},
                    1
            },
            {
                    {{}},
                    {{}},
                    0,
            }
    };

    for (T t : ts) {
        print(t.nums);
        int c = solution.removeDuplicates(t.nums);
        t.nums.resize(t.expect);
        print(t.nums);
        ASSERT_EQ(c, t.expect);
        ASSERT_EQ(t.ret, t.nums);
    }

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


