#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Add Strings

*/


class Solution {
 public:
  string addStrings(string num1, string num2) {
	int c = 0;
	if (num1.size() < num2.size())swap(num1, num2);
	string ret;
	for (int i = 0; i < num1.size(); i++) {
	  int sum = 0;
	  sum += num1[num1.size() - 1 - i]-'0';
	  if (i < num2.size()) {
		sum += num2[num2.size() - 1 - i]-'0';
	  }
	  sum += c;
	  if (sum >= 10) {
		c = 1;
	  } else {
		c = 0;
	  }
	  sum %= 10;
	  ret.push_back(char('0' + sum));
	}
	if (c != 0) {
	  ret.push_back('1');
	}
	reverse(ret.begin(), ret.end());
	return ret;
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


