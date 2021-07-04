#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Count Vowels Permutation

*/

class Solution {
 public:
  int countVowelPermutation(int n) {
	if (n == 1) return 5;
	long ret = long(count('a', n)) + long(count('e', n)) + long(count('i', n)) + long(count('o', n))
		+ long(count('u', n));
	return ret % mod;
  }
 private:
  int mod = 1e9 + 7;
  unordered_map<int, unordered_map<char, int>> memo;
  int count(char c, int n) {
	if (n == 0) {
	  return 0;
	}
	if (n == 1) {
	  return 1;
	}
	{
	  int r = memo[n][c];
	  if (r != 0) {
		return r;
	  }
	}
	vector<char> nxs = nex(c);
	long ret = 0;
	for (char nx : nxs) {
	  ret += count(nx, n - 1);
	  ret %= mod;
	}
	memo[n][c] = ret;
	return ret;
  }
  vector<char> nex(char c) {
	if (c == 'a') {
	  return {'e'};
	} else if (c == 'e') {
	  return {'a', 'i'};
	} else if (c == 'i') {
	  return {'a', 'e', 'o', 'u'};
	} else if (c == 'o') {
	  return {'i', 'u'};
	} else {
	  return {'a'};
	}
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


