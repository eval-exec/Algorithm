#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int concatenatedBinary(int N) {
        long long ret = 0;
        for (int n = 1;n <= N;n++){
            int len = length(n);
            ret = (ret << len) + n;
            ret %= m;
        }
        return ret;
    }
private:
    int m = 1e9 + 7;
    int length(int n){
        int len = 0;
        while(n > 0){
            len++;
            n = n >> 1;
        }
        return len;
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
        cout << solution.concatenatedBinary(2)<< endl;;;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


