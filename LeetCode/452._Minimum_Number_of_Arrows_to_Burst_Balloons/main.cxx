#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

//// START
/*
## 452. Minimum Number of Arrows to Burst Balloons

*/

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](const vector<int> &v0, const vector<int> &v1) -> bool {
           if (v0[0] == v1[0]) {
             return v0[1] < v1[1];
           }
           return v0[0] < v1[0];
         });
    int ans = 0, arrow = 0;
    for (int i = 0; i < points.size(); i++) {
      if (ans == 0 || points[i][0] > arrow) {
        ans++;
        arrow = points[i][1];
      }
    }
    return ans;
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
