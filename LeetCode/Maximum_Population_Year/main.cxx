#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Population Year

*/
class Solution {
  public:
    int maximumPopulation(vector<vector<int>> &logs) {
        map<int, int> mm;
        for (const auto &log : logs) {
            mm[log[0]] += 1;
            mm[log[1]] += -1;
        }
        int mayear = 0;
        int mxp = 0;
        int mp = 0;
        for (auto m : mm) {
            mp += m.second;
            if (mp > mxp) {
                mxp = mp;
                mayear = m.first;
            }
        }
        return mayear;
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


