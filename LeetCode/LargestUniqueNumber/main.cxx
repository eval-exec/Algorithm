#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int largestUniqueNumber(vector<int> &A) {
        vector<int> memo(2000 + 1);
        for (int n : A) {
            memo[n]++;
        }
        for (int i = 2000; i >= 0; i--) {
            if (memo[i] == 1) return i;
        }
        return -1;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


