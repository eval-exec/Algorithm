#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int expressiveWords(string S, vector<string> &words) {
        int ret = 0;
        for (string &word: words) {
            if (verify(S, word)) {
                ret++;
            }
        }
        return ret;
    }

private:
    bool verify(string &w1, string &w2) {
        int len1 = w1.size(), len2 = w2.size();
        if (len1 == 0) {
            if (len2 == 0) {
                return true;
            } else {

                return false;
            }
        }
        if (len2 == 0) return false;
        if (len1 < len2) return false;

        int left = 0, right = 0;

        while (right < len2) {
            if (w1[left] == w2[right]) {
                left++;
                right++;
                continue;
            }
            if (left == 0 || left == len1 - 1) {
                return false;
            }
            if (w1[left] == w1[left - 1]) {
                while (left < len1 && w1[left] == w1[left - 1]) {
                    left++;
                }
                if (!triple(w1, left - 1)) {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (left < len1) {
            if (w1[left] != w1[left - 1]) {
                return false;
            }
            while (left < len1 && w1[left] == w1[left - 1]) {
                left++;
            }
            if (!triple(w1, left - 1)) {
                return false;
            }
        }
        return left == len1;
    }

    bool triple(string &str, int end) {
        if (end <= 1) {
            return false;
        }
        return str[end] == str[end - 2] && str[end] == str[end - 2];
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


