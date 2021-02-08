
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> arr1{0};
        array<int, 26> arr2{0};
        for (char c:s) {
            arr1[c - 'a'] += 1;
        }
        for (char c:t) {
            arr2[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};

struct T {
    string s, t;
    bool result;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    "bbba",
                    "cccx",
                    false,
            },
            {
                    "",
                    "",
                    true,
            },
            {
                    "",
                    "cat",
                    false,
            },
            {
                    "rat",
                    "cat",
                    false,
            },
            {
                    "anagram",
                    "nagaram",
                    true,
            },
    };
    Solution solution;
    for (T t : ts) {
        cout << t.s << " " << t.t << endl;
        EXPECT_EQ(solution.isAnagram(t.s, t.t), t.result);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


