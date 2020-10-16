
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        vector<int> tails;

        if (k >= nums.size()) {
            k %= nums.size();
        }

        if (k == 0) {
            return;
        }

        int len = nums.size();
        for (int i = 0; i < k; i++) {
            tails.push_back(nums.at(len - k + i));
        }

        for (int j = len - 1; j >= k; j--) {
            nums.at(j) = nums.at(j - k);
        }
        for (int i = 0; i < k; i++) {
            nums.at(i) = tails.at(i);
        }

    }
};

void cmp(vector<int> n1, vector<int> n2) {
    ASSERT_EQ(n1.size(), n2.size());
    cout << "size ok" << endl;
    for (int i = 0; i < n1.size(); ++i) {
        ASSERT_EQ(n1.at(i), n2.at(i));
    }
}

void print(vector<int> vs) {
    for (int a : vs) {

        cout << a;

    }
    cout << endl;

}

TEST(Soluton, rotate) {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    solution.rotate(nums, 2);
    cmp(nums, {5, 6, 0, 1, 2, 3, 4});
    print(nums);

    nums = {-1};
    solution.rotate(nums,2);
    cmp(nums,{-1});
    print(nums);

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


