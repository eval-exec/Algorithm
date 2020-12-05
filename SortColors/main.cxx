#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int,3> colors(0);
        for (const int &n:nums){
            if (n == 0 ) colors[0]++;
            if (n == 1) colors[1]++;
            if (n==2) colors[2]++;
        }
        int index=0;
        for (int i = 0;i < 3;i++){
            int color = colors[i];
            while(color > 0){
                nums[index] =i;
                color--;
                index++;
            }
        }
    }
};





struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


