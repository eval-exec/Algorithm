#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isAlphaNumeric(s[left])) {
                left++;
                continue;
            }
            if (!isAlphaNumeric(s[right])) {
                right--;
                continue;
            }
            if (conv(s[left]) == conv(s[right])) {
                left++;
                right--;
                continue;
            }
            return false;
        }
        return true;
    }

private:
    bool isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    int conv(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }
        return c;
    }
};


struct T {
    string s;
    bool result;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    "ax",
                    false,
            },
            {
                    "a",
                    true,
            },
            {
                    "",
                    true,
            },
            {
                    "Ax man, a plan, a canal: Panama",
                    false,
            },
            {
                    "A man, a plan, a canal: Panama",
                    true,
            },
            {
                    "race a car",
                    false,
            },
            {
                    "0P",
                    false,
            },

    };

    Solution solution;

    for (T t : ts) {
        cout << t.s << endl;
        EXPECT_EQ(solution.isPalindrome(t.s), t.result);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


