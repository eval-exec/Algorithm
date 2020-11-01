#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {

        int n1, n2;
        int left = 0;
        int right = nums.size() - 1;
        if (right < 0) {
            return {-1, -1};
        }
        int lastR = right;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
                if (nums[right] != target) {
                    lastR = right;
                }
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] == target) {
            n1 = left;
        } else {
            return {-1, -1};
        }

        right = lastR;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (nums[left] == target) {
            n2 = left;
        } else {
            n2 = left - 1;
        }
        return {n1, n2};
    }
};


struct T {
    vector<int> nums;
    int target;
    vector<int> results;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{5, 7, 7, 8, 8, 10}},
                    8,
                    {{3,  4}},
            },
            {
                    {{5, 7, 7, 8, 8, 10}},
                    6,
                    {{-1, -1}},
            },
            {
                    {{}},
                    0,
                    {{-1, -1}},
            },

    };

    Solution solution;

    for (T t : ts) {
        cout << "checking.." << endl;
        EXPECT_EQ(solution.searchRange(t.nums, t.target), t.results);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


