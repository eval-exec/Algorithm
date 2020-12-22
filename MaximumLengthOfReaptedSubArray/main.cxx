#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int findLength(vector<int> &A, vector<int> &B) {
        vector<int> dp(B.size());
        int ret = 0;
        for (int j = 0; j < B.size(); j++) {
            if (A[0] == B[j]) {
                dp[j] = 1;
                ret = 1;
            }
        }
        for (int i = 1; i < A.size(); i++) {
            vector<int> tmp(B.size());
            tmp[0] = A[i] == B[0] ? 1 : 0;
            for (int j = 1; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    tmp[j] = 1 + dp[j - 1];
                    ret = max(ret, tmp[j]);
                }
            }
            dp = tmp;
        }
        return ret;
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


