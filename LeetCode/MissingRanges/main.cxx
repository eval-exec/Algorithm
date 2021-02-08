#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<vector<int>> rets;
        int len = nums.size();
        if (len == 0) {
            if (lower == upper) {
                rets.push_back({lower});
            } else {
                rets.push_back({lower, upper});
            }
            return conv(rets);
        }

        if (nums[0] == lower + 1) {
            rets.push_back({lower});
        } else if (nums[0] >= lower + 2) {
            rets.push_back({lower, nums[0] - 1});
        }

        for (int i = 1; i < len; i++) {
            int delta = nums[i] - nums[i - 1];
            if (delta > 2) { // 1 4
                rets.push_back({nums[i - 1] + 1, nums[i] - 1});
            } else if (delta == 2) { // 1 3
                rets.push_back({nums[i] - 1});
            }
        }
        if (upper == nums[len - 1] + 1) {
            rets.push_back({upper});
        } else if (upper >= nums[len - 1] + 2) {
            rets.push_back({nums[len - 1] + 1, upper});
        }
        return conv(rets);
    }

private:
    vector<string> conv(vector<vector<int>> &vs) {
        vector<string> rets;
        for (auto &v : vs) {
            if (v.size() == 1) {
                rets.push_back(to_string(v[0]));
            } else {
                rets.push_back(to_string(v[0]) + "->" + to_string(v[1]));
            }
        }

        return rets;
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


