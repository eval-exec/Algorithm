#include<bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    void reverseString(vector<char> &s) {
        int len = s.size();
        int mid = len / 2;
        if (mid == 0) {
            return;
        }
        for (int i = 0; i <= mid; i++) {
            char tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


