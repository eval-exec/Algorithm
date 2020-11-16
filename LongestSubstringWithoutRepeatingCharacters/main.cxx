#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int len = s.size();
        map<char, int> mm;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (mm.find(c) == mm.end()) {
                mm[c] = i;
            } else {
                // 4 5 6 7 8 6
                int dupIndex = mm[c];
                int l = mm.size();
                while (i - dupIndex <= l) {
                    mm.erase(s[dupIndex]);
                    dupIndex--;
                }
                mm[c] = i;
            }
            maxLen = max(maxLen, int(mm.size()));
        }

        return maxLen;

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


