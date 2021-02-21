#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int left = 0, right = height.size()-1;
        int area = 0;
        while(left < right){
            area = max(area,(right - left)*min(height[left],height[right]));
            if (height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;
    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


