#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int MIN = 1;
        int MAX = INT_MIN;
        for (int n: nums) {
            MAX = max(MAX, n);
        }

        while (MIN < MAX) {
            int mid = MIN + (MAX - MIN) / 2;
            int p = process(nums, mid);
            if (p > threshold) {
                MIN = mid + 1;
            } else {
                MAX = mid;
            }
        }
        return MIN;
    }

private:

    int process(vector<int> &nums, int d) {
        int ret = 0;
        for (int &n : nums) {
            ret += div(n, d);
        }
        return ret;
    }

    int div(int a, int b) {
        int ret = a / b;
        if (a % b != 0) {
            ret++;
        }
        return ret;
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


