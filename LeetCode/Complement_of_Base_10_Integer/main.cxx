#include <iostream>
#include <gtest/gtest.h>
#include <bit>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }

        int fake_mask = hob(N);

        fake_mask <<= 1;
        fake_mask -= 1;

        N = ~N;
        int ret = N & fake_mask;
        return ret;

    }

private:

    int hob(int num) {
        if (!num)
            return 0;

        int ret = 1;

        while (num >>= 1)
            ret <<= 1;

        return ret;
    }
};

TEST(Solution, bitwiseComplement) {
    Solution solution;
    GTEST_ASSERT_EQ(2, solution.bitwiseComplement(5));
    GTEST_ASSERT_EQ(0, solution.bitwiseComplement(7));
    GTEST_ASSERT_EQ(5, solution.bitwiseComplement(10));
    GTEST_ASSERT_EQ(1, solution.bitwiseComplement(0));
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
