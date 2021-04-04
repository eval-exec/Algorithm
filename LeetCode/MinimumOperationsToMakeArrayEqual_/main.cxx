#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {

        // 1 3 5 7 9 // 2,4
        // 1 3 5 7 9 11 13 // 2,4,6
        // 1 3 5 7 9 11 // 1,3,5
        // int 
        // 0 2 6 12
        // 1 3
        // 1 3 5 7
        int count= 0;
        if ((n & 1) != 0){
            return  (n-1)*(n/2+1)/2;
        }else{
            return (1+n-1)*(n/2)/2;
        }
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


