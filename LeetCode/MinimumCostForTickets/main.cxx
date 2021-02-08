#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            vector<int> dp(days.size());
            array<int,3> costs_days={1,7,30};
            for (int di = 0;di < days.size();di++){
                int min_d = INT_MAX;
                for (int ci = 0;ci < 3;ci++){
                    int start = days[di] - costs_days[ci]+1;
                    if (start > days[0]){
                        int starti = di;
                        while(days[starti] >= start){
                            starti--;
                        }
                        min_d = min(min_d,costs[ci] + dp[starti]);
                    }else{ // start <= days[0]
                        min_d = min(min_d,costs[ci]);
                    }
                }
                dp[di] = min_d;
            }
            return dp[days.size()-1];
        }
};


struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


