
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        int n = matrix[0].size();
        vector<int> ret(m * n);

        int a = 0, b = 0;
        int count = 0;
        bool down = false;
        while (count < m * n) {
            ret[count] = matrix[a][b];
            if ((a == 0 || b == n - 1) && !down) {
                if (b < n - 1) {
                    b++;
                } else {
                    a++;
                }
                down = true;
                count++;
                continue;
            }
            if ((b == 0 || a == m - 1) && down) {
                if (a < m - 1) {
                    a++;
                } else {
                    b++;
                }
                down = false;
                count++;
                continue;
            }

            if (down) {
                a++;
                b--;
            } else {
                a--;
                b++;
            }
            count++;
        }

        return ret;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


