#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int,int> mm;
        for (int i = S.size()-1 ;i >= 0;i--){
            char c = S[i];
            if (mm.find(c) == mm.end()) mm[c]=i;
        }
        vector<int> rets;
        int len = 0;

        int far = 0;
        for (int i = 0 ;i < S.size();i++){
            len++;
            auto f= mm.find(S[i]);
            if (f->second > far){
                far = f->second;
            }
            if (far == i){
                rets.push_back(len);
                len=0;
            }
        }
        if (len != 0 )rets.push_back(len);
        return rets;
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


