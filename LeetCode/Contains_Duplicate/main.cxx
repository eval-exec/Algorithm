
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> ss;
        for (int n : nums) {
            if (ss.find(n) == ss.end()) {
                ss.insert(n);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


