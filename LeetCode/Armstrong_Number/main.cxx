#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Armstrong Number

*/

class Solution {
public:
    bool isArmstrong(int n) {
      int N = n;
      int count= 0;
	  while(n > 0){
		n /= 10;
		count++;
	  }
	  n = N;
      int sum = 0;
      while(n > 0){
        sum  += pow(n%10,count);
        n /= 10;
      }
      return sum == N;
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


