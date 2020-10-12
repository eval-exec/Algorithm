

#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

/*
 *

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.

 */

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() <= 1 || B.size() <= 1) {
            return false;
        }

        char Afirst = '\0', Asecond = '\0';
        char Bfirst = '\0', Bsecond = '\0';
        int count = 2;

        map<char, uint> m;
        bool hasEqual = false;
        for (int i = 0; i < A.size(); ++i) {
            if (!hasEqual) {
                if (m.count(A.at(i)) == 1) {
                    hasEqual = true;
                } else {
                    m.insert(pair<char, uint>(A.at(i), 1));
                }
            }

            if (A.at(i) == B.at(i)) {
                continue;
            }
            if (count == 2) {
                Afirst = A.at(i);
                Bfirst = B.at(i);
                count--;
            } else if (count == 1) {
                Asecond = A.at(i);
                Bsecond = B.at(i);
                count--;
            } else {
                return false;
            }
        }
        switch (count) {
            case 0:
                return Afirst == Bsecond && Asecond == Bfirst;
            case 1:
                return false;
            default:
                return hasEqual;
        }
    }
};

TEST(solution, buddystrings) {
    Solution solution;
    GTEST_ASSERT_EQ(solution.buddyStrings({"ab"}, {"ba"}), true);
    GTEST_ASSERT_EQ(solution.buddyStrings({"ab"}, {"ab"}), false);
    GTEST_ASSERT_EQ(solution.buddyStrings({"aa"}, {"aa"}), true);
    GTEST_ASSERT_EQ(solution.buddyStrings({"ab"}, {""}), false);
    GTEST_ASSERT_EQ(solution.buddyStrings({""}, {""}), false);
    GTEST_ASSERT_EQ(solution.buddyStrings({"aaaaaaabc"}, {"aaaaaaacb"}), true);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


