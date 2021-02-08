#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    bool stoneGame(vector<int> &piles) {
        return pick(piles, 0, piles.size() - 1, 0, 1, true);
    }
  private:
    bool pick(const vector<int> &piles, int l, int r, int s1, int s2, bool turn) {
        if (l == r) {
            if (turn) {
                return s1 + piles[l] > s2;
            } else {
                return s1 + piles[l] < s2;
            }
        }
        if (turn) {
            return !pick(piles, l + 1, r, s1 + piles[l], s2, !turn)
                || !pick(piles, l, r - 1, s1, s2 + piles[r], !turn);
        } else {
            return !pick(piles, l + 1, r, s1 + piles[l], s2, !turn)
                && !pick(piles, l, r - 1, s1, s2 + piles[r], !turn);
        }
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


