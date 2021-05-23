#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimum Speed to Arrive on Time

*/

class Solution {
 public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
	if (hour +1 < dist.size()) return -1;
	int left = 1, right = 1e7;
	while (left < right) {
	  int mid = left + (right - left) / 2;
	  if (ok(dist, mid, hour)) {
		right = mid;
	  } else {
		left = mid + 1;
	  }
	}
	return left;
  }
  bool ok(const vector<int> &dist, int speed, double hour) {
	double now = 0;
	for (int i = 0; i < dist.size(); i++) {
	  int d = dist[i];
	  double cost = double(d) / speed;
	  int dcost = int(cost);
	  if (i + 1 == dist.size()) {
		now += cost;
	  } else {
		if (cost - dcost == 0) {
		  now += dcost;
		} else {
		  now += dcost + 1;
		}
	  }
	  if (now > hour) return false;
	}
	return true;
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


