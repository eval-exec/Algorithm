#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--;
        n--;
        int index = nums1.size()-1;
        while(index >= 0 ){
            if (m >= 0 && n >= 0){
                
            if (nums2[n] >= nums1[m] ){
                nums1[index] = nums2[n];
                n--;
            }else{
                nums1[index] = nums1[m];
                m--;
            }
            }else if (m >= 0 ){
                nums1[index] = nums1[m];
                m--;
            }else if (n >=0){
                nums1[index] = nums2[n];
                n--;
            }
            index--;
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


