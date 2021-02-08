#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:

    int countPrimes(int n) {
        vector<bool> ss(n + 1);
        for (int i = 2; i <= sqrt(n); i++) {
            if (ss[i]) {
                continue;
            }
            int x = 2;
            while (x * i < n) {
                ss[i * x] = true;
                x++;
            }
        }
        int count = 0;
        for (bool b : ss) {
            if (!b) {

                count++;
            }

        }
        if (n >= 2) {
            return count - 3;
        }
        return 0;
    }

};


struct T {
    int n;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
            {0, 0,},
            {1, 0,},
            {2, 0,},
            {3, 1},
            {
             1000000,
                78498
            },
            {
             5000000,
                0,
            },

            {
             1500000,
                114155
            },
            {
             100,
                25,
            },

            {
             1000,
                168,
            }

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.countPrimes(t.n), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


