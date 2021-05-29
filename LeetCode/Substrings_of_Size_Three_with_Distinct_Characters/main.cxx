#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Substrings of Size Three with Distinct Characters

*/

class Solution {
public:
    int countGoodSubstrings(string s) {
      int count = 0;
      unordered_map<char,int> ss;
      if (s.size() <=2) return 0;
      for (int i = 0;i <= 2;i++){
        ss[s[i]]++;
      }
      if (ss.size() == 3) count=1;
      for (int  i =3;i < s.size();i++){
        ss[s[i]]++;
        ss[s[i-3]]--;
        if (ss[s[i-3]] == 0){
          ss.erase(s[i-3]);
        }
        if (ss.size() == 3)count++;
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


