#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int N = 31;
        uint32_t ret = 0;
        while (N >= 0) {
            bool b = (n & (uint32_t(1) << N)) > 0;

            if (b) {
                ret |= (1 << 31 - N);
            }
            N--;
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


