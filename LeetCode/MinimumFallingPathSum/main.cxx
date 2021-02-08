#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution_recursion {
  public:
    int minFallingPathSum(vector<vector<int>> &A) {
        int sum = INT_MAX;
        for (int i = 0; i < A[0].size(); i++) {
            sum = min(sum, A[0][i] + minSum(A, 1, i));
        }
        return sum;
    }
  private:
    map<pair<int, int>, int> memo;
    int minSum(const vector<vector<int>> &A, int level, int prev_idx) {
        if (level >= A.size()) return 0;
        auto f = memo.find({level, prev_idx});
        if (f != memo.end()) return f->second;

        int min_sum = INT_MAX;
        int start = prev_idx - 1 < 0 ? 0 : prev_idx - 1;
        int end = prev_idx + 1 > A[level].size() - 1 ? A[level].size() - 1 : prev_idx + 1;
        for (int next = start; next <= end; next++) {
            min_sum = min(min_sum, A[level][next] + minSum(A, level + 1, next));
        }
        memo[{level, prev_idx}] = min_sum;
        return min_sum;
    }
};

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &A) {
        vector<int> dp(A[0].size());
        for (int i = 0; i < A[0].size(); i++) {
            dp[i] = A[A.size() - 1][i];
        }

        for (int i = A.size() - 2; i >= 0; i--) {
            vector<int> tmp(A[0].size());
            for (int j = 0; j < A[0].size(); j++) {
                int min_bom = dp[j];
                if (j > 0) min_bom = min(min_bom, dp[j - 1]);
                if (j < A[0].size() - 1) min_bom = min(min_bom, dp[j + 1]);
                tmp[j] = A[i][j] + min_bom;
            }
            dp = tmp;
        }
        return *min_element(dp.begin(), dp.end());
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


