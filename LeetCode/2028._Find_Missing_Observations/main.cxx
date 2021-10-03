#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 2028. Find Missing Observations

*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int total = 0;
      for (auto r : rolls){
	total += r;
      }
      int remains = mean*(rolls.size()+n)  - total;
      vector<int> rets;
      if (remains <= 0)return rets;
      int base = remains /n;
      if (base == 0) return rets;
      int overcount = remains % n;
      if (base > 6 || (base == 6 && overcount > 0))return rets;
      while(n>0){
	n--;
	if (overcount > 0){
	  overcount--;
	  remains -= base+1;
	  rets.push_back(base+1);
	  continue;
	}else{
	  remains -= base;
	  rets.push_back(base);
	}
      }
      return rets;
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


