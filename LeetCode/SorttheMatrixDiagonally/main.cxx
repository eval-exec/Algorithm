#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            int R = mat.size();
            int C = mat[0].size();
            for (int row= 1; row< R;row++){
                vector<int> ns;

                {
                    int r = row,c = 0;
                    while(r < R && c < C){
                        ns.push_back(mat[r][c]);
                        r++;
                        c++;
                    }
                }
                sort(ns.begin(),ns.end());
                {
                    int r = row,c = 0;
                    int i = 0;
                    while(r < R && c < C){
                        mat[r][c] = ns[i];
                        i++;
                        r++;
                        c++;
                    }
                }
            }

            for (int col= 0; col< C;col++){
                vector<int> ns;
                {
                    int r = 0,c = col;
                    while(r < R && c < C){
                        ns.push_back(mat[r][c]);
                        r++;
                        c++;
                    }
                }
                sort(ns.begin(),ns.end());
                {
                    int r = 0,c = col;
                    int i = 0;
                    while(r < R && c < C){
                        mat[r][c] = ns[i];
                        i++;
                        r++;
                        c++;
                    }
                }
            }
            return mat;
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


