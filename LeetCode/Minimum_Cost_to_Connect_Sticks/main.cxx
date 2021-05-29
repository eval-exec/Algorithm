#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimum Cost to Connect Sticks

*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
      priority_queue<int,vector<int>,greater<int>> pq;
      for (int n : sticks){
        pq.push(n);
      }
      int cost= 0;
      while(pq.size() >=2 ){
        int s1 = pq.top();
        pq.pop();
		int s2 = pq.top();
		pq.pop();
		pq.push(s1+s2);
		cost += s1+s2;
      }
      return cost;
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


