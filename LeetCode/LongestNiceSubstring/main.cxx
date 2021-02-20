#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    string longestNiceSubstring(string s) {
        int idx = -1, len = -1;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> ss;
            unordered_set<char> exp;
            for (int j = i; j < s.size(); j++) {
                char c = s[j];
                if (ss.find(c) == ss.end()) {
                    char b = bro(c);
                    if (ss.find(b) == ss.end()) {
                        exp.insert(c);
                        exp.insert(b);
                    }
                }
                exp.erase(c);
                ss.insert(s[j]);
                if (exp.empty()) {
                    if (j - i + 1 > len) {
                        idx = i;
                        len = j - i + 1;
                    }
                }
            }
        }
        if (len >= 2) return s.substr(idx, len);
        return "";
    }
  private:
    char bro(char c) {
        if (c >= 'A' && c <= 'Z') {
            return char(c + 'a' - 'A');
        }
        return char(c - ('a' - 'A'));
    }
};

struct T {
    string s;
};

TEST(Solution, test) {
    T ts[] = {
        {
            "YazaAay"

        },

    };

    for (T t : ts) {
        Solution solution;
        cout << solution.longestNiceSubstring(t.s) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


