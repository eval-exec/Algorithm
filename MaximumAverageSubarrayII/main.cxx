#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double max_value = INT_MIN, min_value = INT_MAX;
        for (int &n : nums) {
            max_value = max(max_value, double(n));
            min_value = min(min_value, double(n));
        }
        if (max_value == min_value) return max_value;

        double err = INT_MAX, pre = INT_MAX;
        while (err >= 1e-6) {
            double mid = min_value + (max_value - min_value) / 2;
            if (check(nums, k, mid)) min_value = mid; else max_value = mid;
            err = abs(pre - mid);
            pre = mid;
        }
        return pre;
    }

private:
    bool check(const vector<int> &nums, const int &k, const double mid) {
        double sum2 = 0;
        for (int i = 0; i < k; i++) {
            sum2 += nums[i] - mid;
        }
        if (sum2 >= 0) return true;

        double preS = 0;
        double min_sum = 0;
        for (int i = k; i < nums.size(); i++) {
            sum2 += nums[i] - mid;
            preS += nums[i - k] - mid;
            min_sum = min(min_sum, preS);
            if (sum2 - min_sum >= 0) return true;
        }
        return false;
    }
};


struct T {
    vector<int> nums;
    int k;
    double expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    .nums={1, 12, -5, -6, 50, 3},
                    .k=4,
                    .expect = 12.75

            },
//            {
//                    .nums={1, 12, -5, -6, 50, 3, 9, 7, 8, 65, 3, 6},
//                    .k=4,
//                    .expect=23.66667
//            }

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_FLOAT_EQ(solution.findMaxAverage(t.nums, t.k), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


