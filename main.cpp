#include <iostream>
#include <gtest/gtest.h>

/*
 *
 * find last item equal to target in a sorted array
 *
 */


class Solution {

private:
    int Bisect_eq_last(const int nums[], const int length, const int target) {
        if (length == 0 || nums[0] > target || nums[length - 1] < target) {
            return -1;
        }

        if (nums[length - 1] == target) {
            return length - 1;
        }


        int low = 0, high = length - 1;


        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                if (nums[mid + 1] != target) {
                    return mid;
                }
                low = mid;
                continue;
            }

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }


        return -1;
    }

public:
    int Find(const int nums[], const int length, const int target) {
        return Bisect_eq_last(nums, length, target);
    }
};

TEST(Solution, Find) {
    int nums[] = {1, 2, 3, 4, 4, 4, 4, 4, 5};
    Solution s;
    EXPECT_EQ(7, s.Find(nums, 9, 4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}

