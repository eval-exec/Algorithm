#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int len = letters.size();
        int l = 0;
        int r = len;
        while (l < r) {
            int mid = (l + r) / 2;
            if (letters[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l == len) {
            return letters[0];
        }
        return letters[l];
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


