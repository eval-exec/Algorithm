#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int n : nums) {
                count += n / mid - 1;
                if (n % mid != 0) count++;
            }
            if (count > maxOperations) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


