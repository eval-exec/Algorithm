#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        multiset<int> ss;
        for (int n : nums) {
            ss.insert(n);
            if (ss.size() > k)ss.erase(ss.begin());
        }
        return *ss.begin();
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


