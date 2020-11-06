#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minDistance(vector<int> &houses, int k) {
        sort(houses.begin(), houses.end());
        int len = houses.size();

        function<int(int, int)> minCost = [&](int i, int j) {
            if (i == j) {
                return 0;
            }
            int half = i + (j - i) / 2;
            int sum = 0;
            for (int a = i; a <= j; a++) {
                sum += abs(houses[a] - houses[half]);
            }
            return sum;
        };


        vector<vector<int>> dp(len, vector<int>(k+1));
        for (int i = 0; i < houses.size(); i++) {
            dp[i][1] = minCost(0, i);
        }
        for (int i = 1; i < houses.size(); i++) {
            for (int j = 2; j <= k; j++) {
                if (j >= i+1) {
                    dp[i][j] = 0;
                    continue;
                }
                int now = INT_MAX;
                for (int p = 0; p < i; p++) {
                    now = min(now, dp[p][j - 1] + minCost(p + 1, i));
                }
                dp[i][j] = now;
            }
        }
        return dp[houses.size() - 1][k];
    }
};


struct T {
    vector<int> houses;
    int k;
    int dis;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 2, 3, 100}},
                    1,
                    100,
            },
            {
                    {{4, 5, 6}},
                    1,
                    2,
            },
            {
                    {{4, 5, 6,7}},
                    1,
                    4,
            },
            {
                    {{1,8,12,10,3}},// 1 3 8 10 12
                    3,
                    4,
            }

    };

    Solution solution;


    for (T t : ts) {
        EXPECT_EQ(solution.minDistance(t.houses, t.k), t.dis);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


