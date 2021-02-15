#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        for (int r = 0; r < mat.size(); r++) {
            mat[r].push_back(r);
        }
        sort(mat.begin(), mat.end(), [](const vector<int> &r1, const vector<int> &r2) -> bool {
            int s1 = 0, s2 = 0;
            for (int i = 0; i < r1.size() - 1; i++) {
                if (r1[i] == 1) s1++;
                if (r2[i] == 1) s2++;
            }
            if (s1 == s2) {
                return r1.back() < r2.back();
            }
            return s1 < s2;
        });
        vector<int> ret;
        for (auto row : mat) {
            ret.push_back(row.back());
            if (ret.size() == k) return ret;
        }
        return ret;
    }
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


