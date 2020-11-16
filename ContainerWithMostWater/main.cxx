#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size();
        int left = 0, right = len - 1;
        int maxArea = 0;
        while (left < right) {
            int l = height[left];
            int r = height[right];

            maxArea = max(maxArea, (right - left) * min(l, r));
            if (l < r) {
                while (left < right) {
                    if (height[left] > l) {
                        break;
                    }
                    left++;
                }
            } else if (l > r) {
                while (left < right) {
                    if (height[right] > r) {
                        break;
                    }
                    right--;
                }
            } else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


