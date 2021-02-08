#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        for (auto &d: digits) {
            ss.push_back(conv(d[0]));
        }
        return solve(n);
    }

    int solve(int n) {
        if (n == 0) return 0;

        int n1 = n;
        int count = 0;
        vector<int> nums;
        while (n1 > 0) {
            nums.push_back(n1 % 10);
            n1 /= 10;
            count++;
        }
        reverse(nums.begin(), nums.end());

        count--;
        int sum = 0;
        while (count > 0) {
            sum += pow(ss.size(), count);
            count--;
        }

        for (int i = 0; i < nums.size(); i++) {
            bool prefix = false;
            for (int s : ss) {
                if (s < nums[i]) {
                    sum += pow(ss.size(), nums.size() - i - 1);
                }
                if (s == nums[i]) {
                    prefix = true;
                    break;
                }
            }
            if (!prefix) return sum;
        }
        return sum + 1;
    }

    vector<int> ss;

    int conv(char &c) {
        return c - '0';
    }
};


struct T {
    vector<string> digits;
    int n;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
//            {
//                    {"1", "3", "5", "7"},
//                    100,
//                    20
//            },
            {
                    {{"1", "3", "5", "7"}},
                    1678,
                    132
            },
//            {
//                    {"1", "4", "9"},
//                    1000000000,
//                    29523
//            }

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.atMostNGivenDigitSet(t.digits, t.n), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


