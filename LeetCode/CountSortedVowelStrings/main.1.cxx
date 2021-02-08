#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int countVowelStrings(int n) {
        return countVowelStrings(1, n);
    }
  private:
    int all = 5;
    unordered_map<long, int> mm;
    int countVowelStrings(int start, int n) {
        if (n == 1) {
            return all - start + 1;
        }
        if (start == 5) {
            return 1;
        }
        auto f = mm.find(n * 6 + start);
        if (f != mm.end()) {
            return f->second;
        }
        int results = 0;
        for (int i = start; i <= all; i++) {
            results += countVowelStrings(i, n - 1);
        }
        mm[n * 6 + start] = results;
        return results;
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


