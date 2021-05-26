#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Partitioning Into Minimum Number Of Deci-Binary Numbers

*/


class Solution {
public:
    int minPartitions(string n) {
      int ret = 0;
      for (char c : n){
        ret = max(ret,c-'0');
      }
      return ret;
    }
};


//// END
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


