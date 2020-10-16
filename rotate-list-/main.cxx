
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


void print(vector<int> vs) {
    for (int a : vs) {
        cout << a;
    }
    cout << endl;
    cout << endl;
}

class Solution {
private:
    void rotatep(vector<int> &nums, int k) {
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

public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
    }


    void rotate1(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

};


void cmp(vector<int> n1, vector<int> n2) {
    cout << "compare ";
    for (int v : n1) {
        cout << v;
    }
    cout << " and ";
    for (int v : n2) {
        cout << v;
    }
    cout << endl;

    ASSERT_EQ(n1.size(), n2.size());
    for (int i = 0; i < n1.size(); ++i) {
        ASSERT_EQ(n1.at(i), n2.at(i));
    }
}

TEST(Soluton, rotate) {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    solution.rotate(nums, 2);
    cmp(nums, {5, 6, 0, 1, 2, 3, 4});
    print(nums);

    nums = {-1};
    solution.rotate(nums, 2);
    cmp(nums, {-1});
    print(nums);

    nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    solution.rotate(nums, 1);
    cmp(nums, {8, 0, 1, 2, 3, 4, 5, 6, 7});
    print(nums);


    nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    solution.rotate(nums, 3);
    cmp(nums, {6, 7, 8, 0, 1, 2, 3, 4, 5});
    print(nums);


    nums = {1, 2};
    solution.rotate(nums, 1);
    cmp(nums, {2, 1});
    print(nums);


    nums = {1, 2, 3, 4, 5, 6};
    solution.rotate(nums, 4);
    cmp(nums, {3, 4, 5, 6, 1, 2});
    print(nums);

    /*
     * 1.2.3.4.5.6.7.8
     * 7.8.3.4.5.6.1.2
     * 7.8.1.2.5.6.3.4
     *
     *
     * 7.8.1.2.3.4.5.6
     * 1.2.3.4.5.6
     *
     *
     *
     *
     * 3.4.5.6.1.2
     */
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


