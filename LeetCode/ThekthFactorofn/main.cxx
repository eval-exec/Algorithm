#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> results;
        if (k > n) return -1;
        double sq = sqrt(n);

        int x = 0;
        int c = 0;
        bool check = true;
        while (c < k && x <= n) {
            x++;
            if (n % x == 0) c++;
            if (check && x >= sq) {
                if (x == sq) {
                    if (2 * (c - 1) + 1 < k) return -1;
                } else {
                    if (2 * c < k) return -1;
                }
                check = false;
            }
        }
        if (c < k) return -1;
        return x;
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


