#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> rets;
        int len = nums.size();
        if (len == 0) {
            return {};
        }

        int lastIndex = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                continue;
            } else {
                string now;
                if (lastIndex == i - 1) {
                    now = to_string(nums[lastIndex]);
                } else {
                    now = to_string(nums[lastIndex]) + "->" + to_string(nums[i - 1]);
                }
                rets.push_back(now);
                lastIndex = i;
            }
        }

        string now;
        if (lastIndex == len - 1) {
            now = to_string(nums[len - 1]);
        } else {
            now = to_string(nums[lastIndex]) + "->" + to_string(nums[len - 1]);
        }
        rets.push_back(now);

        return rets;
    }
};


struct T {
    vector<int> nums;
    vector<string> results;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{0, 2, 3, 4, 6, 8, 9}},
                    {"0",    "2->3", "4", "6", "8->9"}
            },
            {
                    {0},
                    {"0"},
            },
            {
                    {-1},
                    {"-1"},
            },
            {
                    {},
                    {},
            },
            {
                    {{0, 1, 2, 4, 5, 7}},
                    {"0->2", "4->5", "7"},
            },
    };

    Solution solution;

    for (T t : ts) {
        vector<string> ranges = solution.summaryRanges(t.nums);
        int i = 0;
        while (i < ranges.size()) {
            cout << ranges[i] << " " << t.results[i] << endl;
            i++;
        }
        cout << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


