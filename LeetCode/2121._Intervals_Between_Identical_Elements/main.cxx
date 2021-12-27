#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

//// START
/*
## 2121. Intervals Between Identical Elements

*/

class Solution {
public:
  vector<long long> getDistances(vector<int> &arr) {
    unordered_map<int, vector<int>> mm;
    for (int i = 0; i < arr.size(); i++) {
      mm[arr[i]].push_back(i);
    }
    vector<long long> rets(arr.size());
    for (auto m : mm) {
      vector<long long> leftsum(m.second.size());
      int count = 1;
      for (int i = 1; i < m.second.size(); i++) {
        int delta = m.second[i] - m.second[i - 1];
        leftsum[i] = leftsum[i - 1] + count * delta;
        count++;
      }
      rets[m.second.back()] = leftsum.back();

      vector<long long> rightsum(m.second.size());
      count = 1;
      for (int i = m.second.size() - 2; i >= 0; i--) {
        int delta = m.second[i + 1] - m.second[i];
        rightsum[i] = rightsum[i + 1] + count * delta;
        count++;
        rets[m.second[i]] = leftsum[i] + rightsum[i];
      }
    }
    return rets;
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
