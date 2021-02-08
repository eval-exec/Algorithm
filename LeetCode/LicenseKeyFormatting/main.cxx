#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret;
        int n = 0;
        for (auto i = S.rbegin(); i < S.rend(); i++) {
            char c = *i;
            if (isDash(c)) {
                continue;
            }
            ret.push_back(conv(c));
            n++;
            if (n == K) {
                ret.push_back('-');
                n = 0;
            }
        }

        while (*ret.rbegin() == '-') {
            ret.pop_back();
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

private:
    bool isDash(char c) {
        return c == '-';
    }

    char conv(char c) {
        if (c >= '0' && c <= '9') {
            return c;
        }
        if ('a' <= c && c <= 'z') {
            return c - ('a' - 'A');
        }
        return c;
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


