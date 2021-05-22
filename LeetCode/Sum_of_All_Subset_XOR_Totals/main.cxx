#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Sum of All Subset XOR Totals

*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
		dfs(nums,0,0);
		return ret;
    }
	int ret = 0;
	void dfs(const vector<int> &nums,int before,int i){
		if (i == nums.size()) {
			ret += before;
			return ;
		}
		dfs(nums,before ^ nums[i],i+1);
		dfs(nums,before ,i+1);
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


