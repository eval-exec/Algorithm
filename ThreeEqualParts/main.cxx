#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    const vector<int> IMPOSSIABLE{-1, -1};

    vector<int> threeEqualParts(vector<int> &A) {
        int len = A.size();
        int len1 = 0;
        for (const int &a :A) {
            if (a == 1) {
                len1++;
            }
        }
        if (len1 == 0) {
            return {0, len - 1};
        }
        if (len1 % 3 != 0) {
            return IMPOSSIABLE;
        }

        int first, second, third = 0;
        int countSeq = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] == 1) {
                countSeq++;
                if (countSeq == len1 / 3) {
                    first = i;
                }
                if (countSeq == 2 * len1 / 3) {
                    second = i;
                }
                if (countSeq == len1) {
                    third = i;
                }
            }
        }

        /*
         *
         *
         * A[0], A[1], ..., A[i] is the first part;
            A[i+1], A[i+2], ..., A[j-1] is the second part, and
            A[j], A[j+1], ..., A[A.length - 1] is the third part.
         */
        //    100011001000

        int reti = first + len - 1 - third;
        int retj = second + len - third;

        printf("%d %d %d %d %d\n", first, second, third, reti, retj);

        if (check(A, reti + 1, retj - 1, retj, len - 1) == 0 &&
            check(A, 0, reti, retj, len - 1) == 0) {
            return {reti, retj};
        }
        return IMPOSSIABLE;
    }

private:
    int check(vector<int> &A, int m1, int n1, int m2, int n2) {
        int len1 = n1 - m1;
        int len2 = n2 - m2;

        int M1 = m1;
        int M2 = m2;

        if (len1 > len2) {
            if (!allZero(A, m1, m1 + len1 - len2 - 1)) {
                return 1;
            }
            M1 = m1 + len1 - len2;
        }
        if (len1 < len2) {
            if (!allZero(A, m2, m2 + len2 - len1 - 1)) {
                return -1;
            }
            M2 = m2 + len2 - len1;
        }

        for (int i = 0; i <= n1 - M1; i++) {
            if (A[M1 + i] > A[M2 + i]) {
                return 1;
            } else if (A[M1 + i] < A[M2 + i]) {
                return -1;
            }
        }
        return 0;
    }

    bool allZero(vector<int> &A, int i1, int j1) {
        for (int i = i1; i <= j1; i++) {
            if (A[i] == 1) {
                return false;
            }
        }
        return true;
    }
};


struct T {
    vector<int> nums;
    vector<int> expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 0, 1, 0, 1}},
                    {0,  3}
            },
            {
                    {{1, 1, 0, 1, 1}},
                    {-1, -1}
            },
            {
                    {{0, 0, 0}},
                    {0,  2}
            },
            {
                    {{0, 0, 0, 0, 0}},
                    {0,  4}
            }

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.threeEqualParts(t.nums), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


