
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int sum = digits[len - 1] + 1;
        digits[len - 1] = sum % 10;
        int count = sum / 10;
        if (count == 0) {
            return digits;
        }
        for (int i = len - 2; i >= 0; i--) {
            sum = digits[i] + count;
            digits[i] = sum % 10;
            count = sum / 10;
        }
        if (count != 0) {
            vector<int> x = {1};
            x.insert(x.end(), digits.begin(), digits.end());
            return x;
        }
        return digits;

    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


