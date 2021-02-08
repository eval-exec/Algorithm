#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        int left = 1;
        int right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long now = mid * mid;
            if (now == num) {
                return true;
            }
            if (now > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;

    }
};


struct T {
    int num;
    bool result;

};

TEST(Solution, test) {
    T ts[] = {
            {1,  true},
            {4,  true},
            {9,  true},
            {16, true},
            {25, true},
            {36, true},
            {49, true},

            {2,  false},
            {3,  false},
            {5,  false},
            {7,  false},
            {8,  false},
            {10, false},
            {11, false},
            {12, false},
            {13, false},
            {14, false},
            {2000105819,false},

    };

    Solution solution;

    for (T t : ts) {
        cout << t.num << endl;
        EXPECT_EQ(solution.isPerfectSquare(t.num), t.result);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


