#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        n--;
        while (n >= 2) {
            if (isPrimer(n)) {
                count++;
            }
            n--;
        }
        return count;
    }

private:
    bool isPrimer(int n) {
        if (n == 2) {
            return true;
        }

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};


struct T {
    int n;

};

TEST(Solution, test) {
    T ts[] = {
            {

                    10
            },

    };

    Solution solution;

    for (T t : ts) {
        cout << solution.countPrimes(t.n) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


