#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Construct Target Array With Multiple Sums

*/
class Solution {
  public:
    bool isPossible(vector<int> &target) {
        if (target.size() == 1 && *target.begin() == 1) return true;
        map<int, int> tt;
        long tsum = 0;
        for (int t : target) {
            tt[t]++;
            tsum += t;
        }
        long tmp = tsum;
        while (true) {
            int tmax = tt.rbegin()->first;
            long tremain = tsum - tmax;
            if (tmax < tremain) {
                return false;
            }
            if (tremain == 0)return false;
            int p = tmax / tremain;
            if (p >= 2) {
                p--;
            }

            tt[tmax] -= 1;
            tsum -= tmax;
            tt[tmax - tremain * p] += 1;
            tsum += tmax - tremain * p;

            if (tt[tmax] == 0) {
                tt.erase(tmax);
            }
            if (tt.size() == 1 && tt.begin()->first == 1) return true;
            if (tsum == tmp)return false;
            tmp = tsum;
        }
    }
};

//// END

struct T {
    vector<int> target;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .target={1, 1, 1, 2},
        },
        {
            .target={9, 3, 5},
        },
        {
            .target={1, 10000000},
        },
//        {.target={1}},
//        {.target={2}},

    };

    for (T t : ts) {
        Solution solution;
        cout << solution.isPossible(t.target) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


