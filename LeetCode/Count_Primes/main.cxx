#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Count Primes

*/


class Solution {
  public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                isPrime[i * j] = false;
            }
        }
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    Solution solution;
    cout << solution.countPrimes(10) << endl;

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


