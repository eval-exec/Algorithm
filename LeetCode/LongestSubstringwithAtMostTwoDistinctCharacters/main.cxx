#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size();
        map<int, int> mm;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            auto f = mm.find(c);
            if (f != mm.end()) {
                mm[c] = i;
                maxLen = max(maxLen, i - start + 1);
            } else {
                if (mm.size() <= 1) {
                    mm[c] = i;
                    maxLen = max(maxLen, i - start + 1);
                } else {
                    auto m1 = mm.begin();
                    auto m2 = mm.rbegin();
                    if (m1->second < m2->second) {

                        start = m1->second + 1;
                        mm.erase(m1->first);
                    } else {
                        start = m2->second + 1;
                        mm.erase(m2->first);
                    }
                    mm[c] = i;
                }
            }
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


