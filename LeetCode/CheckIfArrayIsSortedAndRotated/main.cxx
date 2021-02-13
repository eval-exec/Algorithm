#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
private:
enum status {
front,
end,
};


public:
    bool check(vector<int>& nums) {
        if (nums.empty()) return true;
        status s = front;
        int last = nums[0];
        int index = 0;
        for (int i = 1 ;i < nums.size();i++){
            int n = nums[i];
            if (s == front){
                if (n < last){
                    s = end;
                    index = i;
                }
            }else{
                if (n < last){
                    return false;
                }
            }
            last = n;
        }
        int len = nums.size();
        if (s == front){
            return true;
        }
        return nums[len-1] <= nums[0];
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


