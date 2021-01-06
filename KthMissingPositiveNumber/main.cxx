#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last = 0;
        for (int i = 0;i < arr.size();i++){
            int n = arr[i];
            if (n - i  > k) {
                if (i == 0 ){
                    return k;
                }else{
                    return arr[i-1] + k-last;
                }
            }else{
                last = n-i-1;
            }
        }
        return arr[arr.size()-1] + k-last;
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


