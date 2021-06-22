#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Number of Matching Subsequences

*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      mm.resize(s.size());
      vector<int> tmp(26,-1);
      for (int i = s.size()-1;i >= 0 ;i--){
	tmp[s[i]-'a']= i;
	mm[i]  = tmp;
      }
      int count = 0;
      for (auto word: words){
	if (is(word)) count++;
      }
      return count;
    }
private:
  vector<vector<int>> mm;
  bool is(const string &word){
    int i = 0;
    for (char c : word){
      if (i >= mm.size()) return false;
      int n = mm[i][c-'a'];
      if (n == -1) return false;
      i = n+1;
    }
    return true;
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


