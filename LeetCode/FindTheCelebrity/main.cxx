#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/*

The knows API is defined for you.


*/

bool knows(int a, int b);

class Solution {
  public:
    int findCelebrity(int n) {
        int candi = 0;
        for (int i = 0; i < n; i++) {
            if (knows(candi, i)) {
                candi = i;
            }
        }
        return isCelebrity(n, candi) ? candi : -1;
    }
  private:
    bool isCelebrity(int n, int c) {
        bool k = false;
        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            if (!knows(i, c) || knows(c, i)) return false;
            k = true;
        }
        return k;
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


