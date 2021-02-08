#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/*

   Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

   The distance between two adjacent cells is 1.


*/
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            R = matrix.size();
            C = matrix[0].size();
            for (int r = 0 ; r < R;r++){
                for (int c = 0 ;c < C;c++){
                    if (matrix[r][c] == 0 ) continue;
                    update(matrix,r,c);
                }
            }
            return matrix;
        }
    private:

        void update(vector<vector<int>> &matrix, int r,int c){
            queue<vector<int>> qq;
            qq.push({r,c});

            vector<vector<bool>> visited(R,vector<bool>(C));
            visited[r][c] = true;

            int steps = 0;
            while(!qq.empty()){
                int qlen = qq.size();
                while(qlen > 0){
                    auto now = qq.front();
                    if (matrix[now[0]][now[1]] == 0) {
                        matrix[r][c] = steps;
                        return;
                    }
                    qq.pop();
                    for (const auto & di: dis){
                        int x = now[0]+di[0];
                        int y = now[1]+di[1];
                        if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y]) continue;
                        visited[x][y]=true;
                        qq.push({x,y});
                    }
                    qlen--;
                }
                steps++;
            }
        }
        int R,C;
        vector<vector<int>> dis= {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0},
        };

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


