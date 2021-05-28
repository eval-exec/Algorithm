#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <sys/cdefs.h>
using namespace std;

//// START
/*
## Maximum Erasure Value 2

*/

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
	unordered_set<int> st;
	int ret = 0;
	int left = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
	  if (st.empty()) {
		st.insert(nums[i]);
		sum += nums[i];
	  } else {
		if (st.find(nums[i]) != st.end()) {
		  while (1) {
			if (nums[left] == nums[i]) {
			  break;
			}
			st.erase(nums[left]);
			sum -= nums[left];
			left++;
		  }
		  st.erase(nums[left]);
		  sum -= nums[i];
		  left++;
		}
		st.insert(nums[i]);
		sum += nums[i];
	  }
	  ret = max(ret, sum);
	}
	return ret;
  }
};

//// END
struct T {};

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
