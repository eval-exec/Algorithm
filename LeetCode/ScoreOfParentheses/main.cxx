#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int scoreOfParentheses(string S) {
        return cal(S, 0, S.size() - 1);
    }
  private:
    int cal(const string &S, int i, int j) {
        if (i >= S.size() || i >= j) return 0;
        if (i + 1 == j) return 1;
        int count = 1;
        for (int left = i + 1; left <= j - 2; left++) {
            if (S[left] == '(') count++;
            else count--;
            if (count == 0) return cal(S, i, left) + cal(S, left + 1, j);
        }
        return 2 * cal(S, i + 1, j - 1);
    }
};

struct T {

    string S;
    int e;
};

TEST(Solution, test) {
    T ts[] = {
        {
            "(((()))()(())(())",
           18
        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.scoreOfParentheses(t.S), t.e);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


