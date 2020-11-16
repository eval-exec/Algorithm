#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int longestMountain(vector<int> &A) {
        int len = A.size();
        if (len <= 2) return 0;
        int maxLen = 0;
        int state = 0; // 0, 1 up, 2 down

        int start = 0;
        for (int i = 0; i < len; i++) {
            switch (state) {
                case 0: // not found start
                    if (i < len - 1) {
                        if (A[i] < A[i + 1]) {
                            state = 1;
                            start = i;
                        }
                    }
                    continue;
                case 1:
                    if (i < len - 1) {
                        if (A[i] == A[i + 1]) {
                            state = 0;
                        } else if (A[i] > A[i + 1]) {
                            state = 2;
                        }
                    }
                    continue;
                case 2:
                    if (i < len - 1) {
                        if (A[i] <= A[i + 1]) {
                            maxLen = max(maxLen, i - start + 1);

                            state = 0;
                            i--;
                        }
                    } else {
                        maxLen = max(maxLen, i - start + 1);
                        break;
                    }
                    continue;
            }
        }


        return maxLen;
    }
};


struct T {
    vector<int> A;
    int expect;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{2, 1, 4, 7, 3, 2, 5}},
                    5
            },
    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.longestMountain(t.A), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


