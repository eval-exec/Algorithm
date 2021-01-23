#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<int> zeros;
        int zero_len = 0;
        int len = 0;
        int max_len = 0;
        for (int i = 0 ;i < A.size(); i++){
            if (A[i] == 1){
                zero_len++;
                len++;
            }else{
                if (K != 0 ){

                    if (zeros.size() == K){
                        max_len = max(max_len,len);
                        len -= zeros[0];
                        zeros.erase(zeros.begin());
                        len--;
                    }
                    zeros.push_back(zero_len);
                    zero_len = 0;
                    len++;
                }else{
                    max_len = max(max_len,len);
                    len = 0;
                }
            }
        }
        max_len = max(max_len,len);
        return max_len;

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

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


