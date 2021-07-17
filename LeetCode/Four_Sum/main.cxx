#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Four Sum


*/
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(),nums.end());
	vector<vector<int>> results;
	for (int i = 0; i < nums.size(); i++) {
	  for (int j = i + 1; j < nums.size(); j++) {
		unordered_set<int> mm;
		for (int k = j + 1; k < nums.size(); k++) {
		  int p = target - nums[i] - nums[j] - nums[k];
		  if (mm.find(p) != mm.end()) {
			results.push_back({nums[i], nums[j], p, nums[k]});
		  }
		  mm.insert(nums[k]);
		}
	  }
	}
	vector<vector<int>> rets;
	if (!results.empty()) {
	  rets.push_back(results[0]);
	}
	for (int i = 1; i < results.size(); i++) {
	  if (results[i] == results[i - 1])continue;
	  rets.push_back(results[i]);
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

  for (T t : ts) {
	Solution solution;

  }
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


