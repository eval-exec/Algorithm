#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> m1;
        for (int a: A) {
            for (int b :B) {
                m1[a + b] += 1;
            }
        }
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                auto f = m1.find(-c - d);
                if (f != m1.end()) {
                    count += f->second;
                }
            }
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


