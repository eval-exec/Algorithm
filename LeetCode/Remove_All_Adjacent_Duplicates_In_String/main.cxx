#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Remove All Adjacent Duplicates In String

*/
class Solution {
public:
    string removeDuplicates(string s) {
      stack<char> st;
      for (char c : s){
	if (st.empty() || st.top() != c){
	  st.push(c);
	}else{
	  st.pop();
	}
      }
      string ret;
      while(!st.empty()){
	ret.push_back(st.top());
	st.pop();
      }
      reverse(ret.begin(),ret.end());
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


