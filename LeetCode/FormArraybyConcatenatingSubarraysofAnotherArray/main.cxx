#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int gi = 0;
        for (int ni = 0; ni < nums.size(); ni++) {
            if (ok(groups[gi], nums, ni)) {
                ni += groups[gi].size()-1;
                gi++;
            }
            if (gi == groups.size()) {
                return true;
            }
        }
        return gi == groups.size();
    }
  private:
    bool ok(const vector<int> &group, const vector<int> &nums, int ni) {
        for (int i = 0; i < group.size(); i++, ni++) {
            if (ni >= nums.size()) return false;
            if (group[i] == nums[ni]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

struct T {
    vector<vector<int>> grousp;
    vector<int> nums;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .grousp={{1, -1, -1}, {3, -2, 0}},
            .nums={1, -1, 0, 1, -1, -1, 3, -2, 0},
        },
    };

    for (T t : ts) {
        Solution solution;
        cout << solution.canChoose(t.grousp, t.nums) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


