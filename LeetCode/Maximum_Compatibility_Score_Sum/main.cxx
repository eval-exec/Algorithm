#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Compatibility Score Sum

*/


class Solution {
 public:
  int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
	int len = students.size();
	string bits;
	bits.resize(len * 2, '0');
	full.resize(len * 2, '1');
	return maxCompatibilitySum(bits, students, mentors);
  }
  int maxCompatibilitySum(string &bits,
						  const vector<vector<int>> &students,
						  const vector<vector<int>> &mentors) {
	{
	  const auto &f = memo.find(bits);
	  if (f != memo.end())return f->second;
	}

	int len = bits.size() / 2;
	if (bits == full) return 0;
	int maxr = 0;
	for (int i = 0; i < len; i++) {
	  if (bits[i] == '1')continue;

	  bits[i] = '1';
	  for (int j = len; j < len * 2; j++) {
		if (bits[j] == '1')continue;

		bits[j] = '1';
		maxr = max(maxr,
				   score(students[i], mentors[j - len])
					   + maxCompatibilitySum(bits, students, mentors));
		bits[j] = '0';
	  }
	  bits[i] = '0';
	}
	memo[bits] = maxr;
	return maxr;
  }
  int score(const vector<int> &v1, const vector<int> &v2) {
	int ret = 0;
	for (int i = 0; i < v1.size(); i++) {
	  if (v1[i] == v2[i])ret += 1;
	}
	return ret;
  }
  string full;
  unordered_map<string, int> memo;
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


