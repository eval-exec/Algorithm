#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
        if (m < n) {
            swap(m, n);
        }
        int delta = m - n;
        if (delta == 0) return m;
        if (wei(m) != wei(n)) return 0;
        int M = m;
        while (n < M) {
            m &= n;
            n++;
        }
        return m;
    }
  private:
    int wei(int n) {
        if (n == 0) return 0;
        int w = 0;
        while (n > 0) {
            n >>= 1;
            w++;
        }
        return w;
    }
};


class Solution_2 {
  public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while(m < n){
            m =>> 1;
            n =>> 1;
            shift++;
        }
        return m << shift;
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


