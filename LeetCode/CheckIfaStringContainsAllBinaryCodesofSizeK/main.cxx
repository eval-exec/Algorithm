#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
  public:
    bool hasAllCodes(string s, int k) {
        int need = (1 << k);
        unordered_set<string> ss;
        for (int i = k; i <= s.size(); i++) {
            string sub = s.substr(i - k, k);
            ss.insert(sub);
            if (ss.size() == need) return true;
        }
        return false;
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


