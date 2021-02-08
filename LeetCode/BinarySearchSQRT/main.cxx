#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long ret;

        while (true) {
            ret = left + (right - left) / 2;
            if (ret * ret <= x && (ret + 1) * (ret + 1) > x) {
                return ret;
            } else if (ret * ret > x) {
                right = ret - 1;
            } else {
                left = ret + 1;
            }
        }
    }
};


struct T {
    int in;
    int out;
};

TEST(Solution, test) {
    T ts[] = {
            {4, 2,},
            {5, 2,},
            {8, 2,},
            {1, 1,},
            {2, 1,},

    };

    Solution solution;

    for (T t : ts) {
        cout << "checking.." << t.in << endl;
        EXPECT_EQ(solution.mySqrt(t.in), t.out);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


