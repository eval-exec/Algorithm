#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
    public:
	int arraySign(vector<int>& nums) {
	    bool ret =true;
	    for (auto n : nums){
		if (n == 0 ) return 0;
		if (n > 0) continue;
		else ret = (!ret);
	    }
	    return ret;
	}
};




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


