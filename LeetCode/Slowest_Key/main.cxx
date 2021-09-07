#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Slowest Key

*/


class Solution {
	public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		auto p = make_pair(keysPressed[0],releaseTimes[0]);
		for (int i = 1;i < releaseTimes.size();i++){
			if (releaseTimes[i] - releaseTimes[i-1] > p.second || releaseTimes[i] - releaseTimes[i-1] == p.second && keysPressed[i] > p.first  ){
				p.first = keysPressed[i];
				p.second = releaseTimes[i] - releaseTimes[i-1];
			}
		}
		return p.first;
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


