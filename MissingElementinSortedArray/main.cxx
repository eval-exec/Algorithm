#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int len = nums.size();
        int start = nums[0], end = nums[len - 1];
        int missingIn = end - start - len + 1;
        if (k > missingIn) {
            return end + k - missingIn;
        }
        int left = 0, right = len - 1;

        // 4 5 6  8 9 11 13
        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] - start - mid < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left--;
        return nums[left] + k - (nums[left] - start - left);
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


