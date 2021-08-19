#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 1668 Minimum Range Cover

*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool cpr(const Interval &i1,const Interval &i2){
	if (i1.start == i2.start) return i1.end < i2.end;
	return  i1.start < i2.start;
}

class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the minimal points number
     */
    int getAns(vector<Interval> &a) {
		int count = 0;
		sort(a.begin(),a.end(),cpr);
		for (int i =  0;i < a.size();i++){
			auto end = a[i].end;

			while(i < a.size() && a[i].start <= end ){
                end = min(a[i].end,end);
				i++;
			}
			i--;
			count++;
		}
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


