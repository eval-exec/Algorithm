#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Performance of a Team

*/



class Solution {
 private:
  long m = 1e9 + 7;
 public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
	vector<vector<int>> es(n);
	for (int i = 0; i < n; i++) {
	  es[i] = {efficiency[i], speed[i]};
	}
	sort(es.begin(), es.end(), [](const vector<int> &v1, const vector<int> &v2) -> bool {
	  return v1[0] > v2[0];
	});
	long spsum = 0;
	long ret = 0;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; i++) {
	  spsum += es[i][1];
	  pq.push(es[i][1]);
	  if (pq.size() == k + 1) {
		spsum -= pq.top();
		pq.pop();
	  }
	  ret = max(ret, spsum * es[i][0]);
	}
	return ret%m;
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


