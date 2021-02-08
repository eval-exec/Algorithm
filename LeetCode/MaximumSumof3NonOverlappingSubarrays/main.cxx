#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int K) {
        int len = nums.size();
        vector<int> sums(len);
        {
            int sum = 0;
            for (int i = 0; i < K; i++) {
                sum += nums[i];
            }

            // 0 1 2 3 4
            for (int i = 0; i <= len - K; i++) {
                sums[i] = sum;
                if (i < len - K) {
                    sum -= nums[i];
                    sum += nums[i + K];
                }
            }
        }
        // 0 1 2 3 4 5 6 7 8
        vector<pair<array<int, 2>, int>> dp1(len);
        {
            vector<pair<int, int>> dp0(len);
            {
                int v = sums[0];
                dp0[0] = {0, v};
                for (int i = 0; i <= len - 3 * K; i++) {
                    if (i > 0) dp0[i] = dp0[i - 1];
                    if (sums[i] > v) {
                        v = sums[i];
                        dp0[i] = {i, v};
                    }
                }
                cout << endl;
            }
            int v = sums[K] + dp0[0].second;
            dp1[K] = {{0, K}, v};
            for (int j = K; j <= len - 2 * K; j++) {
                if (j > K) dp1[j] = dp1[j - 1];
                if (sums[j] + dp0[j - K].second > v) {
                    v = sums[j] + dp0[j - K].second;
                    dp1[j] = {{dp0[j - K].first, j}, v};
                }
            }
        }

        vector<pair<array<int, 3>, int>> dp2(len);
        {
            int v = sums[2 * K] + dp1[K].second;
            dp2[2 * K] = {{0, K, 2 * K}, v};
            for (int k = 2 * K; k <= len - K; k++) {
                if (k > 2 * K) dp2[k] = dp2[k - 1];
                if (sums[k] + dp1[k - K].second > v) {
                    v = sums[k] + dp1[k - K].second;
                    dp2[k] = {{dp1[k - K].first[0], dp1[k - K].first[1], k}, v};
                }
            }
        }
        return vector<int>(dp2[len - K].first.begin(), dp2[len - K].first.end());
    }
};

struct T {
    vector<int> nums;
    int K;
    vector<int> expect;

};

TEST(Solution, test) {
    T ts[] = {
//        {
//            {{1, 2, 1, 2, 6, 7, 5, 1}},
//            2,
//            {{0, 3, 5}}
//        },
        {
            {{1, 5, 6, 8, 9, 7, 5, 3, 1, 3, 1, 2, 1, 2, 3, 4, 5, 2, 1, 2, 6, 7, 5, 1}},
            2,
            {{2, 4, 20}},
        }

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.maxSumOfThreeSubarrays(t.nums, t.K), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


