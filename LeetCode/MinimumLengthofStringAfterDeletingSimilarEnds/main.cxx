#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    int minimumLength(string s) {
        if (s.empty()) return 0;
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) {
                left++;
            }
            if (left > right) return 0;
            while (left <= right && s[right] == c) {
                right--;
            }
        }
        return right - left + 1;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


