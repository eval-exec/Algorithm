#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int len = matrix.size();
        int maxI = len / 2 - 1, maxJ;
        if ((len & 1) == 1) { // 0 1 2 3 4
            maxJ = len / 2;
        } else { // 0 1 2 3 4 5
            maxJ = len / 2 - 1;

        }
        for (int i = 0; i <= maxI; i++) {
            for (int j = 0; j <= maxJ; j++) {
                int tmp = matrix[i][j];
                int ii = 4;
                auto now = make_pair(i, j);
                while (ii > 0) {
                    auto n = next(matrix, now);
                    swap(matrix[n.first][n.second], tmp);
                    now = n;
                    ii--;
                }
            }
        }
    }

private:
    pair<int, int> next(vector<vector<int>> &matrix, pair<int, int> p) {
        int rowLen = matrix.size();
        auto q = make_pair(p.second, p.first);
        return {q.first, rowLen - 1 - q.second};
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


