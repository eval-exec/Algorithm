#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rets;
        gen(n,n,"",rets);
        return rets;
    }
    private:
    void gen(int left,int right,string str,vector<string> &rets){
        if (left == 0 && right == 0 ){
            rets.push_back(str);
            return;
        }
        if (left > 0){
            gen(left-1,right,str+"(",rets);
        }
        if (left < right && right > 0){
            gen(left,right-1,str+")",rets);
        }
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


