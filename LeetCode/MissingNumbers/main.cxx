#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        if (nums[nums.size() - 1] == nums.size() - 1) {
            return nums.size();
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

struct T {
    vector<int> nums;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {0},
                    1,
            },
            {
                    {{3, 0, 1}},
                    2
            },
            {
                    {{9, 6, 4, 2, 3, 5, 7, 0, 1}},
                    8,
            }

    };

    Solution solution;

    for (T t : ts) {
        cout << t.expect << endl;
        EXPECT_EQ(solution.missingNumber(t.nums), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


