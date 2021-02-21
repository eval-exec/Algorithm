#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int brokenCalc(int X, int Y) {
        if (X == Y) return 0;
        if (X > Y) return X - Y;
        int steps = 0;

        if ((Y & 1) != 0) {
            return 1 + brokenCalc(X, Y + 1);
        } else {
            return 1 + brokenCalc(X, Y / 2);
        }
    }
};

struct T {
    int X, Y;
    int e;

};

TEST(Solution, test) {
    T ts[] = {
        {
            2, 3, 2,
        },
        {
            5, 8, 2,
        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.brokenCalc(t.X, t.Y), t.e);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


