#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    bool validMountainArray(vector<int> &arr) {
        if (arr.size() <= 2) return false;
        if (arr[1] <= arr[0]) return false;
        bool inc = true;
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (inc) {

                if (arr[i] > last) {
                    last = arr[i];
                    continue;
                }
                if (arr[i] == last) {
                    return false;
                }
                last = arr[i];
                inc = false;
            } else {
                if (arr[i] >= last) {
                    return false;
                }
                last = arr[i];
            }
        }
        return !inc;
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


