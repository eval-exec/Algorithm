#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Open the Lock

*/


class Solution {
 public:
  int openLock(vector<string> &deadends, string target) {
	unordered_map<string, bool> visited;
	for (auto dead : deadends) {
	  visited[dead] = true;
	}
	if (visited["0000"]) return -1;

	int depth = 0;
	queue<string> qq;
	qq.push("0000");
	while (!qq.empty()) {
	  int qlen = qq.size();
	  while (qlen > 0) {
		qlen--;

		string src = qq.front();
		qq.pop();
		if (src == target) return depth;
		for (int i = 0; i < 4; i++) {
		  {

			string tmp(src);
			if (tmp[i] <= '8') {
			  tmp[i]++;
			} else {
			  tmp[i] = '0';
			}
			if (!visited[tmp]) {
			  visited[tmp]=true;
			  qq.push(tmp);
			}
		  }
		  {

			string tmp(src);
			if (tmp[i] >= '1') {
			  tmp[i]--;
			} else {
			  tmp[i] = '9';
			}
			if (!visited[tmp]) {
			  visited[tmp]=true;
			  qq.push(tmp);
			}
		  }
		}
	  }
	  depth++;
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


