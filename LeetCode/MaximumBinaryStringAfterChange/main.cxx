#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string maximumBinaryString(string binary) {
        int one = 0;
        int len = binary.size();
        if (len <= 1) return binary;
        int zero = len;
        for (int i = 0;i < len;i++){
            if (binary[i] == '0') {
                zero=i;
                break;
            }
        }
        for (int i = zero;i< len;i++){
            if (binary[i] == '1') one++;
            binary[i] = '0';
        }
        for (int i = 0;i < one;i++){
            binary[len-1-i] = '1';
        }
        for (int i = zero;i < len-1;i++){
            if (binary[i] == '0' && binary[i+1]=='0'){
                binary[i] = '1';
            }else{
                break;
            }
        }
        return binary;
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


