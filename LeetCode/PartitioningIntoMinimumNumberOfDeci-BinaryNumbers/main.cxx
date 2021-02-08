#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int minPartitions(string n) {
      // 82734 11111
      // 71624 11111
      // 60514 11111
      // 50403 10111
      // 40302 10101
      // 30101 10101
      // 20000 10101
      // 10000 10000

    }
};

class Solution {
  public:
    int minPartitions(string n) {
      int x = 0;
      for (const char &c: n){
        x = max(x,c-'0')};
    }
    return x;
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


