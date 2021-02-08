#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  private:
    struct vi {
        int value;
        int index;
        vi() {
            value = INT_MAX;
            index = -1;
        }
        vi(int v, int i) {
            value = v;
            index = i;
        }
    };
    struct bro {
        vi min;
        vi min_sec;
    };
  public:
    int minCostII(vector<vector<int>> &costs) {
        if (costs.empty()) return 0;
        bro dp;
        for (int i = 0; i < costs[0].size(); i++) {
            vi tmp;
            if (costs[0][i] < dp.min.value) {
                tmp = dp.min;
                dp.min = {costs[0][i], i};
            } else {
                tmp = {costs[0][i], i};
            }
            if (tmp.value < dp.min_sec.value) {
                dp.min_sec = tmp;
            }
        }

        for (int c = 1; c < costs.size(); c++) {
            bro dp_tmp;
            for (int k = 0; k < costs[0].size(); k++) {
                int last_min = dp.min.value;
                if (dp.min.index == k) {
                    last_min = dp.min_sec.value;
                }
                int now = costs[c][k] + last_min;

                vi tmp;
                if (now < dp_tmp.min.value) {
                    tmp = dp_tmp.min;
                    dp_tmp.min = {now, k};
                } else {
                    tmp = {now, k};
                }
                if (tmp.value < dp_tmp.min_sec.value) {
                    dp_tmp.min_sec = tmp;
                }
            }
            dp = dp_tmp;

        }
        return dp.min.value;
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


