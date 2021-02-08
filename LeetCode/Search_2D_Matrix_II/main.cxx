
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int xx = matrix.size();
        if (xx == 0){
            return false;
        }
        int yy = matrix[0].size();
        int x = 0;
        int y = yy - 1;
        while (true) {
            if (x == xx || y == -1) {
                return false;
            }
            int result = matrix[x][y];
            if (result == target) {
                return true;
            }

            if (result < target) {
                x++;
                continue;
            }

            if (result > target) {
                y--;
                continue;
            }
        }
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


