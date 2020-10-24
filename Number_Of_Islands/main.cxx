
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int xM = grid.size();
        int yM = grid[0].size();
        int count = 0;
        for (int i = 0; i < xM; i++) {
            for (int j = 0; j < yM; j++) {
                if (grid[i][j] == '1') {
                    dig(grid, i, j, xM, yM);
                    count++;
                }
            }
        }

        return count;
    }

    void dig(vector<vector<char>> &grid, int x, int y, int xM, int yM) {
        if (x < 0 || x > xM || y < 0 || y > yM || grid[x][y] == '1') {
            return;
        }
        grid[x][y] = '0';
        dig(grid, x + 1, y, xM, yM);
        dig(grid, x, y + 1, xM, yM);
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


