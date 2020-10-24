
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {

        stack<int> ss;
        vector<int> ret(T.size());
        for (int i = 0; i < T.size(); i++) {
            if (ss.empty()) {
                ss.push(i);
                continue;
            }
            while (!ss.empty()) {
                int topi = ss.top();
                int top = T[topi];
                if (T[i] > top) {
                    ret[topi] = i - topi;
                    ss.pop();
                    continue;
                } else {
                    break;
                }
            }
            ss.push(i);
        }
        while (!ss.empty()) {
            int topi = ss.top();
            ret[topi] = 0;
            ss.pop();
        }
        return ret;
    }
};

struct T {
    vector<int> T;
    vector<int> result;
};

TEST(Solution, dailyTemperature) {
    T ts[] = {
            {
                    {{73, 74, 75, 71, 69, 72, 76, 73}},
                    {{1, 1, 4,  2, 1, 1, 0, 0}},
            },
            {
                    {{1,  2,  3,  4,  5,  6,  7,  8}},
                    {{1, 1, 1,  1, 1, 1, 1, 0}},
            },
            {
                    {{8,  7,  6,  5,  4,  3,  2,  1}},
                    {{0, 0, 0,  0, 0, 0, 0, 0}},
            },
            {
                    {{8,  9,  6,  5,  4,  3,  2,  1}},
                    {{1, 0, 0,  0, 0, 0, 0, 0}},
            },
            {
                    {{8,  7,  6,  5,  4,  3,  2,  10}},
                    {{7, 6, 5,  4, 3, 2, 1, 0}},
            },
            {
                    {{43, 56, 87, 84, 76, 47, 65, 87, 57, 87, 66, 45, 86, 87, 98, 56, 45, 37, 74, 56, 35, 37}},
                    {{1, 1, 12, 4, 3, 1, 1, 7, 1, 5, 2, 1, 1, 1, 0, 3, 2, 1, 0, 0, 1, 0}},
            },
    };
    Solution solution;
    for (T t : ts) {
        const vector<int> &temperatures = solution.dailyTemperatures(t.T);
        EXPECT_EQ(t.result, temperatures);

    }

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


