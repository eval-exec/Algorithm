#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int len = nums.size(), left = 0, right = len - 1;
        if (len == 0) {
            return false;
        }

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int L = nums[left];
            int M = nums[mid];
            int R = nums[right];

            if (L == target || R == target || M == target) {
                return true;
            }
            if (M == L && M == R) {
                return flat(nums, left, right, target);
            }

            if (L <= M) {
                if (L < target && target < M) {
                    left++;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                    right--;
                }
            } else { // M < R
                if (M < target && target < R) {
                    left = mid + 1;
                    right--;
                } else {
                    right = mid - 1;
                    left++;
                }
            }


        }
        return false;
    }

private:
    bool flat(const vector<int> &nums,
              const int i,
              const int j,
              const int target) {
        for (int x = i; x <= j; x++) {
            if (nums[x] == target) {
                return true;
            }
        }
        return false;
    }
};


struct T {
    vector<int> nums;
    int target;

};

TEST(Solution, test) {
    T ts[] = {
//            {
//                    {{2,  5,  6,  0,  0,  1,  2}},
//                    0
//
//            },
//            {
//                    {{16, 21, 26, 35, 40, 41, 48, 1,  3, 8, 12}},
//                    8
//            },
//            {
//                    {{43, 1, 5, 12, 13, 17, 26, 29, 32, 38, 42}},
//                    5
//            }

            {
                    {{15, 15, 24, 30, 30, 33, 41, 41, 1, 5, 8}},
                    1
            }
    };


    for (T t : ts) {
        Solution solution;
        cout << solution.search(t.nums, t.target) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


