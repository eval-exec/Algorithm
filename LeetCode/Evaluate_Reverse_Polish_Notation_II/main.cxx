#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Evaluate Reverse Polish Notation II

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<long> st;
      for (const auto & token:tokens){
        if (token == "+"){
          long a1 = st.top();
          st.pop();
		  long a2 = st.top();
		  st.pop();
		  st.push(a1+a2);

        }else if (token == "-"){
		  long a1 = st.top();
		  st.pop();
		  long a2 = st.top();
		  st.pop();
		  st.push(a2-a1);
		}else if (token == "*"){
		  long a1 = st.top();
		  st.pop();
		  long a2 = st.top();
		  st.pop();
		  st.push(a1*a2);
		}else if (token == "/"){
		  long a1 = st.top();
		  st.pop();
		  long a2 = st.top();
		  st.pop();
		  st.push(a2/a1);
        }else {
		  st.push(stoi(token));
        }
      }
      return st.empty()?0:st.top();
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


