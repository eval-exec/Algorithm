#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int N) {
	    unsigned long long ret=1;
	    int bound = (1<<1);
	    int len =1;
	    for (unsigned long long n=2;n<=N;n++){
		    if (n == bound){
			    bound <<= 1;
			    len++;
		    }
		    ret <<=len;
		    ret+=n;
		    ret %= 1000000007;
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

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


