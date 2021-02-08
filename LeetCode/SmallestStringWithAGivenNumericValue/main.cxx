#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string getSmallestString(int n, int k) {
        string ret;
        for (int i = 0;i < n;i++){
            ret += 'a';
            k--;
        }
        for (int i = n-1;i >= 0;i--){
            if (k == 0 ) break;
            if (k <= 25){
                ret[i]+=k;
                k = 0;
            }else{
                ret[i] = 'z';
                k-=25;
            }
        }
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


    for (T t : ts){
        Solution solution;
        cout << solution.getSmallestString(5,73)<< endl;;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


