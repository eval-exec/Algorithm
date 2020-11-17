#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g;
        q /= g;
        if (even(p)) return 2;
        if (even(q)) return 0;
        return 1;
    }


private:
    bool odd(int n) {
        return !even(n);
    }

    bool even(int n) {
        return n % 2 == 0;
    }

    int gcd(int p, int q) {
        if (p == 0) return q;
        return gcd(q % p, p);
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


