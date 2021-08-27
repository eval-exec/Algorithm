#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Sum of Square Numbers

*/


class Solution {
	public:
	bool judgeSquareSum(long c) {
		long tb = 0;
		long ma= sqrt(c);
		for (long a = ma; a >= ma/2; a--){
			long a2 = a*a;
			for (long b = tb; b*b <= c-a2; b++){
				if (a*a + b*b == c){
					return true;
				}
				else{
					tb = b + 1;
				}
			}
		}
		return false;

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


