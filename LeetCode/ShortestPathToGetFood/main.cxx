#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        R = grid.size();
        C = grid[0].size();
        auto start = find_start(grid);
        vector<vector<bool>> visited;
        visited[start.first][start.second]=true;
        queue<pair<int,int>> qq;
        qq.push(start);
        int steps = 0;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen > 0){
                auto now = qq.front();
                if (grid[now.first][now.second] == '#') return steps;
                qq.pop();

                for (auto direction: directions){
                    int r = now.first + direction.first;
                    int c = now.second + direction.second;
                    if (r < 0 || r >= R) continue;
                    if (c < 0 || c >= C) continue;
                    if (visited[r][c]) continue;
                    if (grid[r][c] == 'X') continue;
                    visited[r][c]=true;
                    qq.push(make_pair(r,c));
                }
                qlen--;
            }
            steps++;
        }
        return -1;
    }
private:
    int R = 0,C = 0;
    vector<pair<int,int>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0},
    };
    pair<int,int> find_start(const vector<vector<char>> & grid){
        for (int r = 0; r < R; r++){
            for (int c = 0;c < C;c++){
                if (grid[r][c] == '*') return make_pair(r,c);
            }
        }
        return make_pair(-1,-1);
    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


