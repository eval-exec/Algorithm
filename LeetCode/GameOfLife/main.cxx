
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;






class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            R = board.size();
            C = board[0].size();
            vector<vector<int>> tmp(board);
            for (int r = 0;r < R;r++){
                for (int c = 0;c<C;c++){
                    int x = board[r][c];
                    int n = neighbors(tmp,r,c);
                    if (n < 2){
                        x=0;
                    }else if (n == 3){
                        x=1;
                    }else if (n > 3){
                        x =0;
                    }
                    board[r][c]=x;
                }
            }
        }
    private:
        int R ;
        int C;
        int neighbors(const vector<vector<int>> & board,int r,int c){
            int n = 0;
            if (r-1>=0){
                n+=board[r-1][c];
                if (c-1>=0){
                    n+=board[r-1][c-1];
                }
                if (c+1<= C-1){
                    n+=board[r-1][c+1];
                }
            }
            if (c-1>=0) n+=board[r][c-1];
            if (c+1<=C-1) n+=board[r][c+1];
            if (r+1<= R-1){
                n+=board[r+1][c];
                if (c-1>=0){
                    n+=board[r+1][c-1];
                }
                if (c+1<= C-1){
                    n+=board[r+1][c+1];
                }
            }
            return n;
        }
};

struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
