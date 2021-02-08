#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:

    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
        len = intervals.size();
        int start = toBeRemoved[0], end = toBeRemoved[1];

        int left = find(intervals, start);
        int right = find(intervals, end);

        vector<vector<int>> rets = cut(intervals, left, right, start, end);
        intervals.erase(intervals.begin() + left, intervals.begin() + right + 1);
        if (!rets.empty()) {
            intervals.insert(intervals.begin() + left, rets.begin(), rets.end());
        }
        return intervals;
    }

private:
    int len = 0;

    vector<vector<int>> cut(vector<vector<int>> &intervals, int leftIndex, int rightIndex, int start, int end) {
        if (start <= intervals[leftIndex][0] && end >= intervals[rightIndex][1]) {
            return {};
        }
        if (start >= intervals[leftIndex][1] && end <= intervals[rightIndex][0]) {
            return {intervals[leftIndex], intervals[rightIndex]};
        }
        vector<vector<int>> rets;
        if (intervals[leftIndex][0] < start) {
            rets.push_back({intervals[leftIndex][0], start});
        }
        if (end <= intervals[rightIndex][0]) {
            rets.push_back(intervals[rightIndex]);
        }else if (end < intervals[rightIndex][1]){
            rets.push_back({end, intervals[rightIndex][1]});
        }
        return rets;
    }

    int find(vector<vector<int>> &intervals, int target) {
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int e = equal(intervals[mid], target);
            if (e > 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int equal(vector<int> &vs, int target) {
        if (target < vs[0]) return -1;
        if (target > vs[1]) return 1;
        return 0;
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


