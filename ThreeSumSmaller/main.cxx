#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution_1 {
  public:
    int threeSumSmaller(vector<int> &nums, int target) {
        multiset<int> mm;
        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            for (int j = i - 2; j >= 0; j--) {
                mm.insert(nums[i - 1] + nums[j]);
            }
            auto f = mm.lower_bound(target - nums[i]);
            int n = distance(mm.begin(), f);
            count += n;
        }
        return count;
    }
};

class Solution {
  public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i++) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] < target) {
                    count += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
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
            {{-2, 0, 1, 3}},
            2,
            2,
        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.threeSumSmaller(t.nums, t.target), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


