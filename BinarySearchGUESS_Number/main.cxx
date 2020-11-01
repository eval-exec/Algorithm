#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        while (true) {
            int mid = left + (right - left) / 2;
            if (guess(mid) == 0) {
                return mid;
            }
            if (guess(mid) > 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
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


