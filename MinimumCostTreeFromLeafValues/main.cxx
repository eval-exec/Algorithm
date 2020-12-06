#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int mctFromLeafValues(vector<int> &arr) {
        int all_sum = 0;
        for (const int &n : arr) {
            all_sum += n;
        }
        int larger_leaf = 0;
        int result = proc(arr, 0, arr.size() - 1, larger_leaf) - all_sum;
        return result;
    }
  private:
    map<pair<int, int>, pair<int, int>> memo;
    int proc(const vector<int> &arr, const int &left, const int &right, int &larger_leaf) {
        {
            auto f = memo.find({left, right});
            if (f != memo.end()) {
                larger_leaf = f->second.second;
                return f->second.first;
            }
        }
        if (left == right) {
            larger_leaf = arr[left];
            int result = arr[left];
            memo[{left, right}] = {result, larger_leaf};
            return result;
        }
        if (left + 1 == right) {
            larger_leaf = max(arr[left], arr[right]);
            int result = arr[left] + arr[right] + arr[left] * arr[right];
            memo[{left, right}] = {result, larger_leaf};
            return result;
        }

        int result = INT_MAX;
        larger_leaf = arr[right];
        for (int i = left; i < right; i++) {
            larger_leaf = max(larger_leaf, arr[i]);
            int larger1 = 0, larger2 = 0;
            int r1 = proc(arr, left, i, larger1);
            int r2 = proc(arr, i + 1, right, larger2);
            result = min(result, r1 + r2 + larger1 * larger2);
        }
        memo[{left, right}] = {result, larger_leaf};
        return result;
    }
};

struct T {
    vector<int> nums;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
        {
            {{6, 2, 4}},
            32
        },
        {
            {{6, 2, 4, 5}},
            58
        },
        {
            {{1, 5, 3, 6, 8, 6, 4, 3, 6, 9, 7, 7, 8, 4, 2, 5, 7, 8, 6, 4, 2, 4, 6, 3}},
            800
        }

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.mctFromLeafValues(t.nums), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


