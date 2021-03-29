#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
    public:
        int reinitializePermutation(int n) {
            vector<int> vv(n);
            for (int i = 0 ;i < n;i++){
                vv[i] = i;
            }
            int ret = 0;
            while(true){
                vector<int> tmp(vv);
                for (int i = 0 ;i < vv.size();i++){
                    if ((i&1) == 0){
                        vv[i] = tmp[i/2];
                    }else{
                        vv[i] = tmp[n/2+(i-1)/2];
                    }
                }
                ret++;
                if (eq(vv)) break;
            }
            return ret;
        }
    private:
        bool eq(const vector<int> &v1){
            for (int i = 0 ; i < v1.size();i++){
                if (v1[i] != i)  return false;
            }
            return true;
        }
};





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


