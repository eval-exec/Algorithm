#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## To Lower Case

*/


class Solution {
public:
    string toLowerCase(string s) {
		const int dt = 'a' - 'A';
		for (int i = 0 ;i < s.size();i++){
			if (s[i] <= 'Z' && s[i] >= 'A'){
				s[i] = char(s[i]+dt);
			}
		}
		return s;
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


