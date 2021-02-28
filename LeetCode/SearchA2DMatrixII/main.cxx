#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        M = matrix.size();
        N = matrix[0].size();

        int m = 0,n = N -1;
        while(valid(m,n)){
            int v = matrix[m][n];
            if (v == target) return true;
            if (target ==  v){
                return true;
            }else if (target > v){
                m++;
            }else{
                n--;
            }
        }
        return false;
    }
private:
    int M = 0;
    int N = 0;
    bool valid(int m,int n){
        return m >= 0 && m < M &&  n >= 0 && n < N;
    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
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


