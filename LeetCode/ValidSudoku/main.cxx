#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char> > grid;
        for (int i = 0; i < 9 * 9; i++) {
            int ri = i / 9;
            int ci = i % 9;
            if (board[ri][ci] == '.') continue;

            if (rows[ri].count(board[ri][ci]) != 0) return false;
            rows[ri].insert(board[ri][ci]);

            if (cols[ci].count(board[ri][ci]) != 0) return false;
            cols[ci].insert(board[ri][ci]);

            int gr = ri / 3;
            int gc = ci / 3;
            int gi = (gr * 3) + gc;

            if (grid[gi].count(board[ri][ci]) != 0) return false;
            grid[gi].insert(board[ri][ci]);
        }
        return true;
    }
  private:
    bool ok(const vector<vector<char>> &board, int ri, int ci, char c) {
        for (int i = 0; i < 9; i++) {
            if (c == board[ri][i]) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (c == board[i][ri]) return false;
        }
        int br = 3 * (ri % 3);
        int bc = 3 * (ci % 3);
        for (int ir = br; ir < br + 3; ir++) {
            for (int ic = bc; ic < bc + 3; ic++) {
                if (board[ir][ic] == c) return false;
            }
        }
        return true;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


