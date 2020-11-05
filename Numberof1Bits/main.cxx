#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n >= 1) {
            if ((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};

struct T {
    uint32_t in;
    int out;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    0b100101011111111111111100101,
                    20,
            },
            {0b1,1},
            {0b10,1},
            {0b0,0},

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.hammingWeight(t.in), t.out);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


