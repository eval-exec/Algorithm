#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Rank Transform of an Array

*/



class Solution {
  public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        set<int> ss;
        for (int i = 0; i < arr.size(); i++) {
            ss.insert(arr[i]);
        }
        unordered_map<int,int> mm;
        int rank = 0;
        for (auto s : ss){
            rank++;
            mm[s] = rank;
        }
        vector<int> rets;
        for (int n : arr){
            rets.push_back(mm[n]);
        }
        return rets;
    }
};
//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


