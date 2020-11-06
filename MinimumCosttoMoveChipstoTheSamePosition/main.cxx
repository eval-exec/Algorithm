#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        if (position.size() <= 1) {
            return 0;
        }
        vector<int> simp = simplify(position);

        return min(simp[0], simp[1]);
    }

private:
    vector<int> simplify(vector<int> &position) {
        vector<int> simp(2);

        for (int p : position) {
            if (p % 2 == 0) {
                simp[0]++;
            } else {
                simp[1]++;
            }
        }
        return simp;
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


