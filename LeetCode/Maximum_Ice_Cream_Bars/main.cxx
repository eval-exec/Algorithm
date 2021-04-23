#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Ice Cream Bars

*/

class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());
        int cc = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (cc + costs[i] <= coins) {
                cc += costs[i];
            } else {
                return i;
            }
        }
        return costs.size();
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


