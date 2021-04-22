#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

//// START ## Missing Number In Arithmetic Progression
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int last = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            int now = arr[i] - arr[i - 1];
            if (now == last) {
                last = now;
                continue;
            }
            if (last == now * 2) {
                return arr[i - 1] - now;
            } else {
                return arr[i - 1] + last;
            }
        }
        return arr.back();
    }
};




//// END




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


