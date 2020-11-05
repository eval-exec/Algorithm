#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        while (x > 0 || y > 0) {
            if ((x & 1) != (y & 1)) {
                distance++;
            }

            x >>= 1;
            y >>= 1;
        }
        return distance;
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


