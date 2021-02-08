#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int count=0;
        for (int i = 0;i < arr.size();i++){
            sum += n;
            if (sum == i *(i+1)/2 ){
                count++;
            }
        }
        return count;
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


