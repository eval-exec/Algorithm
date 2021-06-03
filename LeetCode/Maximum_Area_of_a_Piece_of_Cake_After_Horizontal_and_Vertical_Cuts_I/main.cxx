#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts I

*/

class Solution {
 public:
  int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
	sort(horizontalCuts.begin(), horizontalCuts.end());
	sort(verticalCuts.begin(), verticalCuts.end());
	int mh = 0;
	int hh = h / 2;
	if (h % 2 != 0) {
	  hh++;
	}
	{
	  int last = 0;
	  for (int d : horizontalCuts) {
		mh = max(mh, d - last);
		last = d;
		if (mh >= hh){
		  break;
		}
	  }
	  mh = max(mh, h - last);
	}
	int mw = 0;
	int ww = w/2;
	if (w % 2 != 0) {
	  ww++;
	}
	{
	  int last = 0;
	  for (int d : verticalCuts) {
		mw = max(mw, d - last);
		last = d;
		if (mw >= ww){
		  break;
		}
	  }
	  mw = max(mw, w - last);
	}
	long ret = long(mw) * mh;
	return ret % long(1e9 + 7);
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


