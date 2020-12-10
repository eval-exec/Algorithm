#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> lexicalOrder(int N) {
        vector<int> rets;
        for (int x = 1; x < 10; x++) {
            dfs(x, N, rets);
        }
        return rets;
    }
  private:
    void dfs(int n, int N, vector<int> &rets) {
        if (n > N) return;
        rets.push_back(n);
        for (int i = 0; i < 10; i++) {
            if (n * 10 + i > N) return;
            dfs(n * 10 + i, N, rets);
        }
    }
};
/*
 1 9
 1 10 ...  9 90 91 92 .. 97 98 99 // 10 ~ N
 100 999 100~N
 1000 9999 1000~N
 1 2 3 4 5 6 7 8 9       n-> n
 1 10 11 12 13 2 3 4 5   n< 10; n+N-10
 1 10 11 12 13 14 15 19 2 20 21 22 23 24 25 3 4 5   40 > 25 10; n+N-10



 */

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


