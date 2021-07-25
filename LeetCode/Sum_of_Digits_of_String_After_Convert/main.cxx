#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Sum of Digits of String After Convert

*/

class Solution {
 public:
  int getLucky(string s, int k) {
	vector<int> nums;
	for (char c : s) nums.push_back(c - 'a' + 1);
	int ret = 0;
	for (auto n : nums) {
	  while (n > 0) {
		ret += n % 10;
		n /= 10;
	  }
	}
	k--;
	while (k > 0) {
	  int tmp = 0;
	  while (ret > 0) {
		int c = ret % 10;
		ret /= 10;
		tmp += c;
	  }
	  ret = tmp;
	  k--;
	}
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


