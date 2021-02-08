#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int mi = INT_MAX;
        int maxP = 0;
        for (int p : prices) {
            maxP = max(maxP, p - mi);
            mi = min(mi, p);
        }
        return maxP;
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


