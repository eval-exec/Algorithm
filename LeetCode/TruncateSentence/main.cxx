#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
  public:
    string truncateSentence(string s, int k) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (ok(s[i])) continue;
            n++;
            if (n == k) {
                return s.substr(0, i);
            }

            while (!ok(s[i])) {
                i++;
            }
            i--;
        }
        return s;
    }
  private:
    bool ok(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


