#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 0074 First Bad Version

*/
/**
* class SVNRepo {
*     public:
*     static bool isBadVersion(int k);
* }
* you can use SVNRepo::isBadVersion(k) to judge whether 
* the kth code version is bad or not.
*/
class Solution {
public:
/**
* @param n: An integer
* @return: An integer which is the first bad version.
	*/
	int findFirstBadVersion(int n) {
		int left = 1,right = n;
		while(left < right){
			int mid = left + (right - left)/2;
			if (SVNRepo::isBadVersion(mid)){
				right = mid;
			}else{
				left = mid+1;
			}
		}
		return left;
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


