#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            if (n == 0 ) return true;
            if (flowerbed.size() ==1) return flowerbed[0]== 0;
            if(flowerbed[0] == 0 && flowerbed[1]==0) {
                flowerbed[0]=1;
                n--;
            }
            for (int i = 1;i < flowerbed.size()-1 && n > 0;i++){
                if (flowerbed[i-1]==0&&flowerbed[i] == 0 && flowerbed[i+1]==0 ){
                    n--;
                flowerbed[i]=1;
                }
            }
            if (flowerbed[flowerbed.size()-2] == 0  && flowerbed[flowerbed.size()-1]==0) n--;
            return n <=0;
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


