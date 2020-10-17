
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


    nums = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 2};
    print(nums);
    squares = solution.sortedSquares(nums);
    print(squares);

}

class Solution2 {
public:
    vector<int> sortedSquares(vector<int> &A) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<int> ans = A;
        int i = 0;
        int j = A.size() - 1;
        int n = j;
        while (i <= j) {
            ans[n] = abs(A[i]) > abs(A[j]) ? A[i] * A[i++] : A[j] * A[j--];
            n--;
        }
        return ans;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


