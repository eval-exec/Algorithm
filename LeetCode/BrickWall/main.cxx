#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## BrickWall

*/
class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        int R = wall.size();
        map<int, int> mm;
        int maxLen = INT_MIN, minLen = INT_MAX;
        for (int r = 0; r < R; r++) {
            int length = 0;
            for (int len : wall[r]) {
                length += len;
                mm[length]++;
            }
            maxLen = max(maxLen, length);
            minLen = min(minLen, length);
        }

        int sl = 0;
        for (auto m : mm) {
            if (m.first >= minLen) break;
            sl = max(sl, m.second);
        }
        return R - sl;
    }
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
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


