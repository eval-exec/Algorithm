
/*
Given an array arr of integers,
 check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
        arr[i] == 2 * arr[j]


Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.

        */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();

        for (int i = 0; i < len; i++) {
            if (bisect(arr, arr[i] * 2, i)) {
                return true;
            }
        }
        return false;
    }

private:
    bool bisect(vector<int> &arr, int target, int i) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid != i;
            }
            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

TEST(Solution, checkIfExist) {
    Solution solution;
    vector<int> nums;

    nums = {10, 2, 5, 3};
    ASSERT_EQ(solution.checkIfExist(nums), true);

    nums = {7, 1, 14, 1};
    ASSERT_EQ(solution.checkIfExist(nums), true);

    nums = {3, 1, 7, 11};
    ASSERT_EQ(solution.checkIfExist(nums), false);

    nums = {-10, 12, -20, -8, 15};
    ASSERT_EQ(solution.checkIfExist(nums), true);

    nums = {-2, 0, 10, -19, 4, 6, -8};
    ASSERT_EQ(solution.checkIfExist(nums), false);

    nums = {-2, 1, 0, 0, -19, 4, 6, -8};
    ASSERT_EQ(solution.checkIfExist(nums), true);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


