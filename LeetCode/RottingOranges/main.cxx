#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        di.push_back(make_pair(0, 1));
        di.push_back(make_pair(0, -1));
        di.push_back(make_pair(1, 0));
        di.push_back(make_pair(-1, 0));

        queue<pair<int, int>> qq;
        R = grid.size();
        C = grid[0].size();
        map<int, bool> visited;
        int good = 0;
        for (int r = 0 ;r < R;r++){
            for (int c = 0 ;c < C;c++){
                if (grid[r][c] == 2){
                    qq.push(make_pair(r,c));
                    visited[ha(r,c)] = true;
                }
                if (grid[r][c] == 1) good++;
            }
        }
        if (qq.empty()){
            if (good == 0 ) return 0;
            return -1;
        }
        int days=0;
        int rotten = 0;
        while (!qq.empty()) {
            int n = qq.size();
            while (n > 0) {
                auto now = qq.front();
                qq.pop();
                for (const auto &d : di) {
                    int r = now.first + d.first;
                    int c = now.second + d.second;
                    if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == 1 && !visited[ha(r, c)]) {
                        visited[ha(r, c)] = true;
                        grid[r][c] = 2;
                        rotten++;
                        qq.push(make_pair(r, c));
                    }
                }
                n--;
            }
            days++;
        }
        if (good != rotten) return -1;
        days--;
        return days;
    }
    vector<pair<int, int>> di;
    int R = 0, C = 0;
    int ha(int r, int c) {
        return r * C + c;
    }
};

struct T {
    vector<vector<int>> in;
    int out;

};

TEST(Solution, test) {
    T ts[] = {
        {
            {{2,1,1},{1,1,0},{0,1,1}},
            4
        },
        {
            {{1,1,1},{1,1,0},{0,1,1}},
            -1
        },
        {
            {{2,0,0},{1,0,0}},
            1
        },

    };

    for (T t : ts) {
    Solution solution;
    EXPECT_EQ(solution.orangesRotting(t.in),t.out);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


