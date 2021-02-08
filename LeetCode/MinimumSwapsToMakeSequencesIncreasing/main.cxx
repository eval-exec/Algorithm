#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int minSwap(vector<int> &A, vector<int> &B) {
        vector<bool> breaks(A.size());
        vector<bool> swaps(A.size());
        for (int i = 1; i < A.size(); i++) {
            if ((max(A[i - 1], B[i - 1]) < min(A[i], B[i]))) {
                breaks[i - 1] = true;
                continue;
            }
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                swap(A[i], B[i]);
                swaps[i] = true;
            }
        }
        return cal(breaks, swaps);
    }

private:
    int cal(vector<bool> breaks, vector<bool> swaps) {
        int len = 0;
        int sp = 0;
        int ret = 0;
        for (int i = 0; i < breaks.size(); i++) {
            len++;
            if (swaps[i]) sp++;
            if (breaks[i]) {
                ret += min(sp, len - sp);
                sp = 0;
                len = 0;
            }
        }
        ret += min(sp, len - sp);
        return ret;
    }
};


class Solution_wrong {
public:
    int minSwap(vector<int> &A, vector<int> &B) {
        vector<bool> breaks(A.size());
        vector<bool> swaps(A.size());
        for (int i = 1; i < A.size(); i++) {
            if ((max(A[i - 1], B[i - 1]) < min(A[i], B[i]))) {
                breaks[i] = true;
                continue;
            }
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                swap(A[i], B[i]);
                swaps[i] = true;
            }
        }
        return cal(breaks, swaps);
    }

private:
    int cal(vector<bool> breaks, vector<bool> swaps) {
        int len = 0;
        int sp = 0;
        int ret = 0;
        for (int i = 0; i < breaks.size(); i++) {
            if (swaps[i]) sp++;
            len++;
            if (breaks[i]) {
                ret += min(sp, len - sp);
                sp = 0;
                len = 1;
            }
        }
        ret += min(sp, len - sp);
        return ret;
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


