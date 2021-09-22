#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Max Consecutive Ones

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int ret = 0;
		int c = 0;
		if (nums[0] == 1){
			c = 1;
			ret = 1;
		}
		for (int i = 1;i < nums.size();i++){
			if (nums[i] == 0){
				c = 0;
				continue;
			}
			if (nums[i] == nums[i-1]){
				c++;
			}else{
				c = 0;
			}
			ret = max(ret,c);
		}
		return ret;
        
    }
};



//// END
struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
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


