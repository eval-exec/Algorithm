#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
private:
    int invert(int a) {
        return a == 1 ? 0 : 1;
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int rowLen = A[0].size();
        for (int r = 0; r < A.size(); r++) {
            for (int i = 0; i < rowLen / 2; i++) { // 0 1 2, // 0 1 2 3
                int a = A[r][i];
                int b = A[r][rowLen - i - 1];
                A[r][i] = invert(b);
                A[r][rowLen - i - 1] = invert(a);
            }
            if (rowLen % 2 == 1) {
                A[r][rowLen / 2] = invert(A[r][rowLen / 2]);
            }
        }

        return A;
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


