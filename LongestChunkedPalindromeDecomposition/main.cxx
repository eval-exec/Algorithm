#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int longestDecomposition(string text) {
        return longestDecomposition(text, 0, text.size() - 1);
    }
  private:
    int longestDecomposition(const string &text, int start, int end) {
        if (end < start) return 0;
        if (end == start) return 1;
        if (end - start == 1) return text[start] == text[end] ? 2 : 1;

        int e1 = start, s2 = end;
        while (e1 <= s2) {
            if (equal(text, start, e1, s2, end)) {
                int result = 2 + longestDecomposition(text, e1 + 1, s2 - 1);
                return result;
            } else {
                e1++;
                s2--;
            }
        }
        return 1;
    }
    bool equal(const string &text, int s1, int e1, int s2, int e2) {
        return text.substr(s1, e1 - s1 + 1).compare(text.substr(s2, e2 - s2 + 1)) == 0;
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


