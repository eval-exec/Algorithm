#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        if (mat.empty()) return 0;
        R = mat.size(), C = mat[0].size();
        pre_sum.resize(R, vector<int>(C));
        pre_sum[0][0] = mat[0][0];
        for (int c = 1; c < C; c++) {
            pre_sum[0][c] = pre_sum[0][c - 1] + mat[0][c];
        }
        for (int r = 1; r < R; r++) {
            pre_sum[r][0] = pre_sum[r - 1][0] + mat[r][0];
        }

        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                pre_sum[r][c] = mat[r][c] + pre_sum[r - 1][c] + pre_sum[r][c - 1] - pre_sum[r - 1][c - 1];
            }
        }
        int left = 1, right = min(R, C);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (ok(mid, threshold)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
  private:
    bool ok(int len, int threshol) {
        if (pre_sum[len - 1][len - 1] <= threshol) return true;
        for (int c = len; c < C; c++) {
            if (pre_sum[len - 1][c] - pre_sum[len - 1][c - len] <= threshol) return true;
        }
        for (int r = len; r < R; r++) {
            if (pre_sum[r][len - 1] - pre_sum[r - len][len - 1] <= threshol)return true;
        }
        for (int r = len; r < R; r++) {
            for (int c = len; c < C; c++) {
                if (pre_sum[r][c] - pre_sum[r - len][c] - pre_sum[r][c - len] + pre_sum[r - len][c - len]
                    <= threshol)
                    return true;
            }
        }
        return false;
    }
    vector<vector<int>> pre_sum;
    int R = 0;
    int C = 0;
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


