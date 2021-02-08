/*
 *
 *Given an array A of non-negative integers,
 * return an array consisting of all the even elements of A,
 * followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int left = 0;
        int len = A.size();
        int right = len - 1;
        while (left < right) {
            if (A[left] % 2 == 0) {
                left++;
                continue;
            }
            if (A[right] % 2 == 1) {
                right--;
                continue;
            }
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
            left++;
            right--;
        }
        return A;
    }
};

void print(vector<int> vs) {
    for (int v : vs) {
        cout << v << " ";
    }
    cout << endl;
}

Solution soluton;

void test(vector<int> &nums) {
    print(nums);
    soluton.sortArrayByParity(nums);
    print(nums);
    cout << endl;
}

TEST(Solution, sotArrayByParity) {

    vector<int> nums;

    nums = {3, 1, 2, 4};
    test(nums);


    nums = {1};
    test(nums);


    nums = {2};
    test(nums);

    nums = {2,4,6,8};
    test(nums);


    nums = {2,4,6,8,1};
    test(nums);


    nums = {2,4,6,1,8};
    test(nums);


    nums = {2,1,4,6,1,8};
    test(nums);


    nums = {2,1,4,5,3,6,1,8};
    test(nums);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


