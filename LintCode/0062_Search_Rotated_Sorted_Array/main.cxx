#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 0062 Search Rotated Sorted Array

*/

class Solution {
public:
/**
* @param A: an integer rotated sorted array
* @param target: an integer to be searched
* @return: an integer
	*/
	int search(vector<int> &A, int target) {
		if (A.empty()) return -1;
		// write your code here
		int head = A[0],tail = A[A.size()-1];
		int left = 0 ,right = A.size()-1;
		if (target >= head){
			while(left < right){
				int mid = left + (right-left)/2;
				if (A[mid] < target  && A[mid] >= head){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			if (left < A.size()){
				if (A[left] != target) return -1;
				return left;
			}else{
				return -1;
			}
		}else{
			while(left < right){
				int mid = left + (right-left)/2;
				if (A[mid] < target && A[mid] <= tail || A[mid] >= head ){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			if (left < A.size()){
				if (A[left] != target) return -1;
				return left;
			}else{
				return -1;
			}
		}
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


