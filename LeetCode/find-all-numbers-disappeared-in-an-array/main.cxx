/*
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime?

You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

 1,2,3,3,4,4,7,8
Output:
[5,6]

 */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ret;
        int len = nums.size();
        if (nums.empty() || len == 1) {
            return nums;
        }

        sort(nums.begin(), nums.end());

        int n = 1;
        for (int v: nums) {
            if (v == n) {
                n++;
                continue;
            } else if (v > n) {
                for (; n < v; n++) {
                    ret.push_back(n);
                }
                n = v + 1;
            }
        }

        if (n <= len) {
            for (;n <= len;n++){
                ret.push_back(n);
            }
        }
        return ret;
    }
};

void print(vector<int> vs) {
    for (int v : vs) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, findDisappeardNumbers) {
    Solution solution;

    vector<int> nums;
    nums = {4, 3, 2, 7, 8, 2, 3, 1};

    print(nums);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);


    nums = {1, 1, 1, 1, 1, 1, 1, 8};
    print(nums);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);


    nums = {1, 1};
    print(nums);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);


    nums = {1, 1, 1, 1, 1, 1, 1, 1};
    print(nums);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);

    nums = {1, 1, 1, 1, 1, 2, 2, 2};
    print(nums);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);

    nums = {27, 40, 6, 21, 14, 36, 10, 19, 44, 10, 41, 26, 39, 20, 25, 19, 14, 7, 29, 27, 40, 38, 11, 44, 4, 6, 48, 39,
            9, 13, 7, 45, 41, 23, 31, 8, 24, 1, 3, 5, 28, 11, 49, 29, 18, 4, 38, 32, 24, 15};


    print(nums);
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    print(tmp);
    nums = solution.findDisappearedNumbers(nums);
    print(nums);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


