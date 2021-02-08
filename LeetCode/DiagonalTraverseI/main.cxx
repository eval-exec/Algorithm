#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        R = matrix.size();
        if (matrix[0].empty()) return {};
        C = matrix[0].size();
        int r = 0, c = 0;
        bool up = true;
        int i = 0;
        vector<int> rets(R *C);
        while (i < R * C) {
            rets[i] = matrix[r][c];
            auto p = next(r, c, up);
            r = p.first;
            c = p.second;
            i++;
        }
        return rets;
    }
  private:
    int R;
    int C;
    pair<int, int> next(int r, int c, bool &up) {
        if (up) {
            if (r == 0 && c <= C - 2) {
                up = false;
                c++;
            } else if (c == C - 1) {
                r++;
                up = false;
            } else {
                r--;
                c++;
            }
        } else {
            if (c == 0 && r <= R - 2) {
                r++;
                up = true;
            } else if (r == R - 1) {
                c++;
                up = true;
            } else {
                c--;
                r++;
            }
        }
        return make_pair(r, c);
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


