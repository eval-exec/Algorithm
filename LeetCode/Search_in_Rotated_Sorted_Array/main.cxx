#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int min = 0;
        while (left < right) {
            min = left + (right - left) / 2;
            if (nums[min] > nums[right]) {
                left = min + 1;
            } else {
                right = min;
            }
        }
        min = left;
        if (min == 0) {
            left = 0;
            right = nums.size() - 1;
        } else {
            if (target >= nums[0]) {
                left = 0;
                right = min - 1;
            } else {
                left = min;
                right = nums.size() - 1;
            }
        }
        printf("%d %d\n", left, right);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid - 1;
                continue;
            } else {
                left = mid + 1;
                continue;
            }
        }
        return -1;
    }
};


struct T {
    vector<int> nums;
    int target;
    int expect;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{4, 5, 6, 7, 0, 1, 2}},
                    0,
                    4,
            },
    };

    Solution solution;
    for (T t : ts) {
        EXPECT_EQ(solution.search(t.nums, t.target), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


