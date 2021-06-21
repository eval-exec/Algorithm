#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Pascalxs Triangle

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> rets;
      for (int r = 1;r <= numRows;r++){
	vector<int> row;
	for (int i = 0;i < r;i++){
	  if (i == 0 || i +1 == r){
	    
	  row.push_back(1);
	  }else{
	    row.push_back(rets.back()[i-1]+rets.back()[i]);
	  }
	}
	rets.push_back(row);
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


