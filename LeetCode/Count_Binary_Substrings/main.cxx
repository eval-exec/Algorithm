#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Count Binary Substrings

*/
class Solution {
  public:
    int countBinarySubstrings(string s) {
        int count = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] != s[i + 1]) {
                // i-1,i,i+,i+2
                count++;
                int left = i - 1, right = i + 2;
                while (left >= 0 && right < s.size()) {
                    if (s[left] == s[left + 1] && s[right] == s[right - 1]) {
                        count++;
                        left--;
                        right++;
                    } else {
                        break;
                    }
                }
            }
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

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


