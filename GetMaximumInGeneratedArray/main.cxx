#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    public:
    unordered_map<int,int> mm;
    int max_v = INT_MIN;
    int getMaximumGenerated(int n) {
        while(n >= 0){
            cal(n);
            n--;
        }
        return max_v;

    }
    int cal(int n) {
        int ret = 0;
        if (n <= 1){
            ret = n;
        }else{
            auto f = mm.find(n);
            if (f != mm.end()){
                return f->second;
            }
            if ((n & 1) == 0 ) {
                ret = cal(n >> 1);
            }else{
                ret = cal(n >> 1) + cal((n >> 1) + 1);
            }
        }
        mm[n] = ret;
        max_v = max(max_v,ret);
        return ret;
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


