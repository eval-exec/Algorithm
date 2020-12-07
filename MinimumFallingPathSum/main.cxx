#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
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


