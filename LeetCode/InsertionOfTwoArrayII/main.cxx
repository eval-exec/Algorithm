#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mm;
        for (auto n : nums2) {
            mm[n]++;
        }
        vector<int> ret;
        for (auto n : nums1) {
            const auto &f = mm.find(n);
            if (f == mm.end())continue;
            mm[n]--;
            if (mm[n] == 0 ){
                mm.erase(n);
            }
            ret.push_back(n);
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


