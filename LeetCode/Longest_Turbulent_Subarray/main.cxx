#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Longest Turbulent Subarray

*/

class Solution {
	public:
	int maxTurbulenceSize(vector<int>& arr) {
		auto dp = make_pair(1,1);
		int ret = 0;
		for (int i = 0;i +1 < arr.size();i++){
			if (arr[i ] > arr[i+1]){
				if (i % 2 != 0){
					dp.first += 1;
					dp.second = 1;
				}else{
					dp.second += 1;
					dp.first = 1;
				}
			}else if (arr[i] < arr[i+1]){
				if (i % 2 != 0){
					dp.second+= 1;
					dp.first = 1;
				}else{
					dp.first += 1;
					dp.second = 1;
				}
			}else{
				dp.first = 1;
				dp.second = 1;
			}
			ret = max(ret,max(dp.first,dp.second));
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


