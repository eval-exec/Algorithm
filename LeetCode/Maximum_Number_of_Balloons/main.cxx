#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Number of Balloons

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
		vector<int> nums(26);
		for (char c : text){
			nums[c - 'a']++;
		}
		int count = INT_MAX;
		count  = min(count,nums['b'-'a']);
		count  = min(count,nums['a'-'a']);
		count  = min(count,nums['l'-'a']/2);
		count  = min(count,nums['o'-'a']/2);
		count  = min(count,nums['n'-'a']);
		return count;
        
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


