#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() <=2) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> rets;
        int head = nums[0];
        while (true) {
            auto l = lower_bound(nums.begin(), nums.end(), head);
            if (l == nums.end()) break;
            head = *l;
            if (head > 0) break;

            int head_idx = l - nums.begin();
            head_idx++;
            if (head_idx >= nums.size()) break;

            auto fd = fd2(nums, head_idx, -head);
            for (const auto &v : fd) {
                rets.push_back({head, v[0], v[1]});
            }
            head++;
        }
        return rets;
    }

    vector<vector<int>> fd2(const vector<int> &nums, int start, const int &targetSum) {
        vector<vector<int>> rets;
        int end = nums.size() - 1;
        while (start < end) {
            int nstart = nums[start];
            int nend = nums[end];
            if (nums[start] + nums[end] == targetSum) {
                rets.push_back({nstart, nend});

                while (start < nums.size() && nums[start] == nstart) {
                    start++;
                }
                while (end > start && nums[end] == nend) {
                    end--;
                }
            } else if (nstart + nend < targetSum) {
                start++;
            } else {
                end--;
            }
        }
        return rets;
    }


    vector<vector<int>> fd1(const vector<int> &nums, int start, const int &targetSum) {
        vector<vector<int>> rets;

        for (int first = nums[start], second = INT_MAX; first <= second;) {
            auto f = lower_bound(nums.begin(), nums.end(), first);
            if (f == nums.end()) break;
            first = *f;
            if (first > targetSum - first) break;
            auto l = lower_bound(nums.begin(), nums.end(), targetSum - first);
            if (l != nums.end()) {
                second = *l;
                if (second + first == targetSum) {
                    if (first != second || l + 1 != nums.end() && *(l + 1) == first) {
                        rets.push_back({first, second});
                    }
                }
            }
            first++;
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


