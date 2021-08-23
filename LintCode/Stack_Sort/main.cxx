#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Stack Sort

*/

class Solution {
public:
/*
* @param stk: an integer stack
* @return: void
	*/
	void stackSorting(stack<int>& stk) {
		stack<int> st;
		while(!stk.empty()){
			auto now = stk.top();
			stk.pop();
			if (st.empty()){
				st.push(now);
			}else{
				int n = 0;
				while (!st.empty() && now > st.top()){
					stk.push(st.top());
					st.pop();
					n++;
				}
				st.push(now);
				while(n > 0){
					n--;
					st.push(stk.top());
					stk.pop();
				}
			}
		}
		while(!st.empty()){
			stk.push(st.top());
			st.pop();
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


