#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int countCornerRectangles(vector<vector<int>> &grid) {
        unordered_map<int, int> mm;
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();
        int count = 0;
        for (int r = 0; r < R; r++) {
            vector<int> ones;
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    ones.push_back(c);
                }
            }
            for (int i = 0; i < int(ones.size()) - 1; i++) {
                for (int j = i + 1; j < int(ones.size()); j++) {
                    count += mm[ones[i] * C + ones[j]];
                    mm[ones[i] * C + ones[j]]++;
                }
            }
        }
        return count;
    }
};

struct T {
    vector<vector<int>> ins;
};

TEST(Solution, test) {
    T ts[] = {
//        {
//            .ins={
//                {0, 1, 0},
//                {1, 0, 1},
//                {1, 0, 1},
//                {0, 1, 0},
//            }
//        },
//        {
//            .ins={{1, 1, 1, 0, 1, 0, 0},
//                  {0, 0, 1, 1, 0, 1, 0},
//                  {0, 0, 1, 1, 1, 1, 0}, // 3 1
//                  {1, 0, 0, 1, 1, 1, 1}, // 1 3 1
//            }
//        },
        {
            {{1, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 1}}
        }

    };

    for (T t : ts) {
        Solution solution;
        cout << solution.countCornerRectangles(t.ins) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


