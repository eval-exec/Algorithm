#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Check if Word Equals Summation of Two Words

*/


class Solution {
 public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
	return numw(firstWord) + numw(secondWord) == numw(targetWord);
  }
 private:
  int numw(const string &word) {
    if (word.empty()) return 0;
	int n = 0;
	int f = 0;
	for (int i = word.size() - 1; i >= 0; i--) {
	  f += pow(10, n) * (word[i] - 'a');
	  n++;
	}
	return f;
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


