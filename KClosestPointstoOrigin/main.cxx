#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) -> bool {
            return pow(v1[0], 2) + pow(v1[1], 2) <= pow(v2[0], 2) + pow(v2[1], 2);
        });
        vector<vector<int>> rets(K);
        for (int i = 0; i < K; i++) {
            rets[i] = points[i];
        }
        return rets;
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


