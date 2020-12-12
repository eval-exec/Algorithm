#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int consecutiveNumbersSum(int N) {
        int count = 1;

        int n = 2;
        while (n < N) {
            //  1 2 3 4 5
            //  1 2 3 4 5 6 7 8
            int x = N / n;

            if (n % 2 == 0) { // 1 2 3 4 // 1 2 3
                if (x < n / 2) break;
                if (N == (x + (x + 1)) * n / 2) {
                    count++;
                }
            } else { // 1 2 3 4 5
                if (x < n / 2 + 1) break;
                if (N == x * n) {
                    count++;
                }
            }
            n++;
        }
        return count;
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


