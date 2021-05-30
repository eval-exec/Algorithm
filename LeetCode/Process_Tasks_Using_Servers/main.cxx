#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Process Tasks Using Servers

*/

struct serv {
  int index;
  int weight;
  serv(int i, int w) : index(i), weight(w) {
  }
};

struct job {
  int index;
  long free;
  job(int i, int f) : index(i), free(f) {
  }
};
struct jobFree {
  bool operator()(const job &j1, const job &j2) {
	return j1.free > j2.free;
  }
};

struct serverWeight {
  bool operator()(const serv &s1, const serv &s2) {
	if (s1.weight == s2.weight) {
	  return s1.index > s2.index;
	}
	return s1.weight > s2.weight;
  }
};

class Solution {
 public:
  vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
	priority_queue<serv, vector<serv>, serverWeight> spq;
	priority_queue<job, vector<job>, jobFree> doing;
	vector<int> rets;
	for (int i = 0; i < servers.size(); i++) {
	  spq.push(serv(i, servers[i]));
	}
	int ti = 0;
	for (long now = 0; ti < tasks.size();) {
	  if (!doing.empty() && doing.top().free == now) {
		while (!doing.empty() && doing.top().free == now) {
		  spq.push(serv(doing.top().index, servers[doing.top().index]));
		  doing.pop();
		}
	  }
	  while (!spq.empty() && ti <= now && ti < tasks.size()) {
		auto tser = spq.top();
		spq.pop();

		doing.push(job(tser.index, now + tasks[ti]));
		rets.push_back(tser.index);

		ti++;
	  }
	  if (ti == tasks.size()) break;

	  if (doing.size() == servers.size()) {
		now = doing.top().free;
	  } else {
		now++;
		if (now > doing.top().free) {
		  now = doing.top().free;
		}
	  }
	}
	return rets;
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

  Solution solution;
  vector<int> s1 = {1, 2, 3};
  vector<int> s2 = {5, 4, 3, 1, 2};

  for (int s : solution.assignTasks(s1, s2)) {
	cout << s << " ";
  }
  cout << endl;

}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


