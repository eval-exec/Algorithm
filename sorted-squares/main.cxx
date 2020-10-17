
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        if (A.empty()) {
            return {};
        }
        int len = A.size();
        vector<int> ret(len);
        int left = 0;
        int right = len - 1;
        while (left <= right) {
            if (abs(A.at(left)) < abs(A.at(right))) {
                // left < right
                ret.at(right - left) = pow(A.at(right), 2);
                right--;
            } else {
                // left >= right
                ret.at(right - left) = pow(A.at(left), 2);
                left++;
            }
        }
        return ret;
    }
};

void print(vector<int> nums) {
    for (int v : nums) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, sortedSquares) {
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    print(nums);
    vector<int> squares = solution.sortedSquares(nums);
    print(squares);

    nums = {-1};
    print(nums);
    squares = solution.sortedSquares(nums);
    print(squares);


    nums = {-2, -1, 0};
    print(nums);
    squares = solution.sortedSquares(nums);
    print(squares);

    nums = {0};
    print(nums);
    squares = solution.sortedSquares(nums);
    print(squares);

    nums = {-20, -1, 3, 30};
    print(nums);
    squares = solution.sortedSquares(nums);
    print(squares);

}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


