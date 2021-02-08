#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        if (stones.empty()) return 0;
        unordered_set<int> st;
        st.insert(stones[0]);
        int sum = stones[0];
        for (int i = 1; i < stones.size(); i++) {
            unordered_set<int> tmp(st);
            int n = stones[i];
            sum += n;
            st.insert(n);
            for (const int &s : tmp) {
                st.insert(n + s);
            }
        }
        for (int i = sum / 2; i >= 0; i--) {
            if (st.count(i) != 0) return sum - i * 2;
        }
        return -1;
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


