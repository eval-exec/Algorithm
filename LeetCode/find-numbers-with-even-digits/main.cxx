
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int> &nums) {
        int count = 0;
        for (int v: nums) {
            if (evenCount(v)) {
                count++;
            }
        }
        return count;
    }

private:
    bool evenCount(int n) {
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count % 2 == 0;
    }
};

struct T {
    vector<int> nums;
    int expect;

    T(vector<int> v, int e) {
        nums = v;
        expect = e;
    }
};

TEST(Solution, findNumbers) {
    Solution solution;

    vector<T> ts = {
            {
                    {12,  345, 2,   6, 7896},
                    2
            },
            {
                    {555, 901, 482, 1771},
                    1,
            },
            {
                    {},
                    0

            },

            {

                    {22},
                    1
            },
    };

    for (T t : ts) {
        ASSERT_EQ(t.expect, solution.findNumbers(t.nums));
    }


}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


