#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int deep = 0;
        int max_deep = n % 2 == 0 ? n / 2-1 : n / 2 ;
        int start = 1;
        while (deep <= max_deep) {
            start = fill(matrix, deep, start);
            deep++;
        }
        return matrix;
    }
  private:
    int fill(vector<vector<int>> &matrix, int deep, int start) {
        int len = matrix.size();
        if (len % 2 == 1 && deep == len / 2 ) {
            matrix[deep][deep] = start;
            return start + 1;
        }

        for (int i = deep; i <= len - 1 - deep; i++, start++) {
            matrix[deep][i] = start;
        }

        for (int i = deep + 1; i <= len - 1 - deep - 1; i++, start++) {
            matrix[i][len - 1 - deep] = start;
        }
        for (int i = len - 1 - deep; i >= deep; i--, start++) {
            matrix[len - 1 - deep][i] = start;
        }

        for (int i = len - 1 - deep - 1; i >= deep + 1; i--, start++) {
            matrix[i][deep] = start;
        }
        return start;
    }
};



class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int deep = 0;
        // 0 1 2 3 4 5 //6
        // 0 1 2 3 4   //5
        int max_deep = n % 2 == 0 ? n / 2 - 1 : n / 2;
        int start = 1;
        while (deep <= max_deep) {
            start = fill(matrix, deep, start);
            deep++;
        }
        return matrix;
    }
  private:
    int fill(vector<vector<int>> &matrix, int deep, int start) {
        int len = matrix.size();
        if (len % 2 == 1 && deep == len / 2 + 1) {
            matrix[deep][deep] = start;
            return start + 1;
        }

        for (int i = deep; i <= len - 1 - deep; i++, start++) {
            matrix[deep][i] = start;
        }

        for (int i = deep + 1; i <= len - 1 - deep - 1; i++, start++) {
            matrix[i][len - 1 - deep] = start;
        }
        for (int i = len - 1 - deep; i >= deep; i--, start++) {
            matrix[len - 1 - deep][i] = start;
        }

        for (int i = len - 1 - deep - 1; i >= deep + 1; i--, start++) {
            matrix[i][deep] = start;
        }
        return start;
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


