#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> &A, int K) {
        sort(A.begin(), A.end());
        int len = A.size();
        int left = 0, right = len - 1;
        int ret = -1;
        while (left < right) {
            int sum = A[left] + A[right];
            if (sum < K) {
                ret = max(ret, sum);
                left++;
            } else {
                right--;
            }
        }
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


