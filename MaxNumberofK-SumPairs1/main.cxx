#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mm;
        int count = 0;
        for (int n : nums){
            auto f = mm.find(k-n);
            if (f == mm.end()){
                mm[n]++;
            }else{
                 count++;
                if (f->second == 1){
                    mm.erase(k-n);
                }else{
                    mm[k-n]--;
                }
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


