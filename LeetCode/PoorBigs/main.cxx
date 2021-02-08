#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(n + 1));
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


