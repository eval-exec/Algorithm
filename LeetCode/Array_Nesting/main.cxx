#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Array Nesting

*/
class Solution {
	public:
	int arrayNesting(vector<int>& nums) {
		unordered_map<int,bool> visited;
		int ret= 0;
		for (int i  = 0; i < nums.size();i++){
			if (visited[nums[i]]) continue;
			visited[nums[i]]=true;
			int length = 1;
			int last = nums[i];
			while(1){
				if (!visited[nums[last]]){
					visited[nums[last]]=true;
					last = nums[last];
					length++;
				}else{
					break;
				}
			}
			ret = max(ret,length);
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


