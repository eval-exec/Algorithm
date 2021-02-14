#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int countHomogenous(string s) {
        if (s.empty()) return 0;
        long ret = 0;
        int len = s.size();
        int lasti = 0;
        char last = s[0];
        for (int i = 1; i < len; i++) {
            if (s[i] == last) {
                continue;
            } else {
                ret += cal(i - lasti);
                //
                last = s[i];
                lasti = i;
            }
        }
        ret += cal(len - lasti);
        return ret % long(1e9 + 7);
    }
  private:
    long cal(int n) {
        return long(1 + n) * n / 2;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


