#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int> &data) {
        int len = data.size();
        int win = count_if(data.begin(), data.end(), [](const int &n) -> bool { return n == 1; });
        int zeros = 0;
        for (int i = 0; i < win; i++) {
            if (data[i] == 0)zeros++;
        }
        int ret = zeros;
        for (int i = win; i < len; i++) {
            if (data[i] == 0) zeros++;
            if (data[i - win] == 0) zeros--;
            ret = min(ret, zeros);
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


