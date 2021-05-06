#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Distinct Numbers in Each Subarray

*/

class Solution {
  public:
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        unordered_map<int, int> memo;

        int start = 0;
        for (; start < k; start++) {
            memo[nums[start]]++;
        }
        if (k == nums.size()) {
            return {int(memo.size())};
        }
        vector<int> rets(nums.size() - k + 1);
        rets[0] = memo.size();
        for (int i = k; i < nums.size(); i++) {
            memo[nums[i]]++;
            memo[nums[i - k]]--;
            if (memo[nums[i - k]] == 0)memo.erase(nums[i - k]);
            rets[i - k + 1] = memo.size();
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


