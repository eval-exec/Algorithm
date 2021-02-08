/*
Given an array nums,
 write a function to move all 0's to the end of it while maintaining the relative
 order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int len = nums.size();
        for (int j = 0; j <= len - 1; j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (int m = i; m <= len - 1; m++) {
            nums[m] = 0;
        }
    }
};

void print(vector<int> vs) {
    for (int v: vs) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, moveZeors) {
    Solution solution;
    vector<int> nums;

    nums = {0, 1, 0, 3, 12};
    print(nums);
    solution.moveZeroes(nums);
    print(nums);


    nums = {};
    print(nums);
    solution.moveZeroes(nums);
    print(nums);

    nums = {0};
    print(nums);
    solution.moveZeroes(nums);
    print(nums);


    nums = {1,2,3,4,5};
    print(nums);
    solution.moveZeroes(nums);
    print(nums);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


