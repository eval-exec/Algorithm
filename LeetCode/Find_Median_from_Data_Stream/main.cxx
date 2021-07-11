#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Find Median from Data Stream

*/

class MedianFinder {
  priority_queue<int> lo;
  priority_queue<int, vector<int>, greater<int>> hi;
 public:
  MedianFinder() {
  }

  void addNum(int num) {
	lo.push(num);

	hi.push(lo.top());
	lo.pop();

	if (lo.size() < hi.size()) {
	  lo.push(hi.top());
	  hi.pop();
	}

  }

  double findMedian() {
	return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



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


