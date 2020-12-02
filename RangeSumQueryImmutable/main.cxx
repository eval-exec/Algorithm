#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) return;
        sum = vector<int>(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        int first = i == 0 ? 0 : sum[i - 1];
        int second = j >= sum.size() ? sum[sum.size() - 1] : sum[j];
        return second - first;
    }

private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */



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


