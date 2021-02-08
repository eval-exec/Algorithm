#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
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


