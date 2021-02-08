
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh = haystack.size();
        int lenn = needle.size();
        if (lenn > lenh) {
            return -1;
        }
        if (lenn == 0) {
            return 0;
        }

        int needleSum = sum(needle, 0, lenn);

        int haySum = sum(haystack, 0, lenn);
        if (haySum == needleSum) {
            if (check(haystack, needle, 0, lenn)) {
                return 0;
            }
        }

        for (int i = 0; i <= lenh - lenn - 1; i++) {
            haySum -= haystack[i];
            haySum += haystack[lenn + i];
            if (haySum == needleSum) {
                if (check(haystack, needle, i + 1, lenn)) {
                    return i+1;
                }
            }
        }
        return -1;
    }

private:
    bool check(const string &str, const string &needle, const int &index, const int &lenn) {
        for (int i = 0; i < lenn; i++) {
            if (str[index + i] == needle[i]) {
                continue;
            }
            return false;
        }
        return true;
    }

    int sum(string &str, int index, int len) {
        int s = 0;
        for (int i = 0; i < len; i++) {
            s += str[index + i];
        }
        return s;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


