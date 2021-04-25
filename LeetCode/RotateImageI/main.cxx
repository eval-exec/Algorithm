#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
  ## RotateImageI


*/
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
	int len = matrix.size();
	for (int ri = 0; ri < len / 2; ri++) {
	  for (int ci = 0; ci < len; ci++) {
		swap(matrix[ri][ci], matrix[len - 1 - ri][ci]);
	  }
	}
	for (int ri = 0; ri < len; ri++) {
	  for (int ci = 0; ci <= ri; ci++) {
		swap(matrix[ri][ci], matrix[ci][ri]);
	  }
    }
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


