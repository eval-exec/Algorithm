#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Longer Contiguous Segments of Ones than Zeros

*/

class Solution {
 public:
  bool checkZeroOnes(string s) {
	int lm1s = 0, lm0s = 0;
	if (s[0] == '1') {
	  lm1s = 1;
	} else {
	  lm0s = 0;
	}

	int last = s[0];
	int lastlen= 1;
	for (int i = 1;i < s.size();i++){
	  if (s[i] == last){
	    lastlen++;
	  }else{
	    last = s[i];
	    lastlen =1;
	  }
	  if (s[i] == '1'){
	    lm1s = max(lastlen,lm1s);
	  }else{
		lm0s= max(lastlen,lm0s);
	  }
	}
	return lm1s > lm0s;
  }
};

//// END
struct T {

};

TEST(Solution, test) {
  T ts[] = {
	  {

	  },
	  {

	  },

  };

  for (T t : ts) {
	Solution solution;

  }
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


