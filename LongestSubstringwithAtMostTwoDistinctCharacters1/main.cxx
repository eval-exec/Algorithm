#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int maxLen = 2;
        map<int, int> mm;
        mm[s[0]] += 1;
        mm[s[1]] += 1;

        for (int i = 2, j = 0; i < s.size(); i++) {
            mm[s[i]] += 1;
            while (mm.size() > 2) {
                mm[s[j]]--;
                if (mm[s[j]] == 0) {
                    mm.erase(s[j]);
                }
                j++;
            }

            maxLen = max(maxLen, i - j + 1);
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


