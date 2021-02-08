#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;




// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            }
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
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

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


