#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Reduce Array Size to The Half

*/



class Solution {
 public:
  int minSetSize(vector<int> &arr) {
	int size = arr.size();
	unordered_map<int, int> mm;
	for (int n : arr) {
	  mm[n]++;
	}
	vector<int> cc;
	for (auto m : mm) {
	  cc.push_back(m.second);
	}
	sort(cc.begin(), cc.end());
	int count = 0;
	for (int i = cc.size() - 1; i >= 0; i--) {
	  count += cc[i];
	  if (count * 2 >= size) {
		return cc.size() - i;
	  }
	}
	return -1;
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


