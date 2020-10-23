
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        int i = 0;
        int j = len - 1;
        while (true) {
            if (i >= j){
                return {};
            }
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


