#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int len = seats.size();
        int maxlen = -1;
        if (seats[0] == 0) {
            for (int i = 0; i < len; i++) {
                if (seats[i] == 1) {
                    maxlen = i;
                    break;
                }
            }
        }

        if (seats[len - 1] == 0) {
            for (int i = len - 1; i >= 0; i--) {
                if (seats[i] == 1) {
                    maxlen = max(len - 1 - i, maxlen);
                    break;
                }
            }
        }

        int last = -1;
        for (int i = 0; i < len; i++) {
            if (seats[i] == 1) {
                if (last == -1) {
                    last = i;
                    continue;
                } else {
                    maxlen = max(maxlen, (i - last) / 2);
                    last = i;
                }
            }
        }
        return maxlen;

    }
};


struct T {
    vector<int> seats;
    int result;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 0, 0, 0, 1, 0, 1}},
                    2,
            },
            {
                    {{1, 0, 0, 0}},
                    3,
            },
            {
                    {{0, 0, 0, 1}},
                    3,
            },
            {
                    {{1, 1, 0, 1}},
                    1,
            },
            {
                    {{1, 1, 0, 1, 1, 1, 1}},
                    1,
            },
            {
                    {{0, 1}},
                    1,
            },
            {
                    {{0, 1, 0, 1, 0}},
                    1,
            }

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.maxDistToClosest(t.seats), t.result);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


