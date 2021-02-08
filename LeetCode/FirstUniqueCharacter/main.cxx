
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 26> arr{0};
        for (char si : s) {
            arr[si - 'a'] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

struct T {
    string s;
    int result;
};
TEST(Solution, test) {
    Solution solution;

    T ts[] = {
            {
                    "leetcode",
                    0,
            },
            {
                    "loveleetcode",
                    2,
            },
            {
                    "lllvvxfjewio",
                    5,
            },
            {
                    "",
                    -1,
            },
            {
                    "x",
                    0,
            },
            {
                    "xx",
                    -1,
            },
    };
    for (T t : ts) {
        cout << t.s << endl;
        EXPECT_EQ(solution.firstUniqChar(t.s), t.result);
    }
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


