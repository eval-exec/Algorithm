
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution2 {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() < 3) {
            return false;
        }
        bool haver = false;
        bool haved = false;
        int tmp = A[0];
        int len = A.size();
        for (int i = 1; i < len; i++) {
            int v = A[i];
            if (v == tmp) {
                return false;
            }
            if (v > tmp) {
                if (haved) {
                    return false;
                } else {
                    haver = true;
                }
            }
            if (v < tmp) {
                if (!haver) {
                    return false;
                } else {
                    haved = true;
                }

            }
            tmp = v;
        }
        return haver && haved;
    }
};


class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() < 3) {
            return false;
        }
        int i = 1;
        int len = A.size();
        while (i <= len - 1 && A[i] > A[i - 1]) {
            i++;
        }

        if (i == 1 || i == len) {
            return false;
        }

        while (A[i] < A[i - 1] && i <= len - 1) {
            i++;
        }

        return i == len;

    }
};

TEST(Solution, validaMountainArray) {
    Solution solution;
    vector<int> nums;
    nums = {2, 1};
    bool b = solution.validMountainArray(nums);
    ASSERT_EQ(b, false);

    cout << "ok" << endl;

    nums = {3, 5, 5};
    b = solution.validMountainArray(nums);
    ASSERT_EQ(b, false);

    cout << "ok" << endl;

    nums = {0, 3, 2, 1};
    b = solution.validMountainArray(nums);
    ASSERT_EQ(b, true);
    cout << "ok" << endl;


    nums = {2, 0, 2};
    b = solution.validMountainArray(nums);
    ASSERT_EQ(b, false);
    cout << "ok" << endl;


    nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    b = solution.validMountainArray(nums);
    ASSERT_EQ(b, false);
    cout << "ok" << endl;

    nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    b = solution.validMountainArray(nums);
    ASSERT_EQ(b, false);
    cout << "ok" << endl;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


