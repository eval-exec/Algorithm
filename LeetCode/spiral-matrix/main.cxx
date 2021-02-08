
#include <bits/stdc++.h>
#include <gtest/gtest.h>


using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int lm = matrix.size();
        if (lm == 0) {
            return {};
        }
        int ln = matrix[0].size();
        int m = 0, n = 0;
        int m1 = lm - 1, n1 = ln - 1;

        vector<int> ret;
        while (true) {
            vector<int> r = run(matrix, m, n, m1, n1);
            if (r.empty()) {
                break;
            }
            ret.insert(ret.end(), r.begin(), r.end());
            m++;
            n++;
            m1--;
            n1--;
        }
        return ret;
    }

private:
    vector<int> run(vector<vector<int>> &matrix, int m, int n, int m1, int n1) {
        if (m > m1 || n > n1) {
            return {};
        }
        vector<int> ret;
        if (m == m1) {
            for (int i = n; i <= n1; i++) {
                ret.push_back(matrix[m][i]);
            }
            return ret;
        }
        if (n == n1) {
            for (int i = m; i <= m1; i++) {
                ret.push_back(matrix[i][n]);
            }
            return ret;
        }

        for (int i = n; i <= n1; i++) {
            ret.push_back(matrix[m][i]);
        }
        for (int i = m + 1; i < m1; i++) {
            ret.push_back(matrix[i][n1]);
        }

        for (int i = n1; i >= n; i--) {
            ret.push_back(matrix[m1][i]);
        }

        for (int i = m1 - 1; i > m; i--) {
            ret.push_back(matrix[i][n]);
        }

        return ret;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


