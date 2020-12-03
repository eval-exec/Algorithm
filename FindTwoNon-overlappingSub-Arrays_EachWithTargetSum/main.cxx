#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int> &arr, int target) {
        int len = arr.size();
        vector<vector<int>> dp(arr.size(), vector<int>{len + 1, len + 1});

        {
            map<int, int> r_end_sum;

            int total_sum = arr[0];
            r_end_sum[total_sum] = 0;
            dp[0][0] = arr[0] == target ? 1 : len + 1;
            for (int i = 1; i < arr.size(); i++) {

                total_sum += arr[i];
                r_end_sum[total_sum] = i;
                if (arr[i] == target) {
                    dp[i][0] = 1;
                } else if (total_sum == target) {
                    dp[i][0] = i + 1;
                } else {
                    auto f = r_end_sum.find(total_sum - target);
                    if (f == r_end_sum.end()) {
                        dp[i][0] = dp[i - 1][0];
                    } else {
                        dp[i][0] = min(dp[i - 1][0], i - f->second);
                    }
                }

            }

            if (r_end_sum.count(target) == 0 ) return -1;

            if (target > total_sum) return -1;
            if (target == total_sum) return len;
        }

        {

            map<int, int> l_end_sum;
            int total2 = arr[len - 1];
            l_end_sum[total2] = len - 1;
            dp[len - 1][1] = arr[len - 1] == target ? 1 : len + 1;
            for (int i = len - 2; i >= 0; i--) {

                total2 += arr[i];
                l_end_sum[total2] = i;
                if (arr[i] == target) {
                    dp[i][1] = 1;
                } else if (total2 == target) {
                    dp[i][1] = len - i;
                } else {
                    auto f = l_end_sum.find(total2 - target);
                    if (f == l_end_sum.end()) {
                        dp[i][1] = dp[i + 1][1];
                    } else {
                        dp[i][1] = min(dp[i + 1][1], f->second - i);
                    }
                }

            }
        }

        for (auto d : dp) {
            cout << d[0] << " ";
        }
        cout << endl;
        for (auto d : dp) {
            cout << d[1] << " ";
        }
        cout << endl << endl;

        int ret = len + 1;
        for (int i = 0; i < len - 1; i++) {
            auto left = dp[i][0];
            auto right = dp[i + 1][1];
            if (left == len + 1 || right == len + 1) {
                continue;
            }
            ret = min(ret, left + right);
        }
        if (ret == len + 1) return -1;
        return ret;
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


