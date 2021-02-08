#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,int> mm;
        for (int i = 0;i < pieces.size();i++){
            mm[pieces[i][0]] = i;
        }
        int index = 0;
        while(index < arr.size()){
            auto f = mm.find(arr[index]);
            if (f == mm.end()) return false;
            if (!eq(arr,index,pieces[f->second])) return false;
            index+=pieces[f->second].size();
        }
        return true;
    }
private:
    bool eq(const vector<int> &arr,const int& index, const vector<int> &piece){
        if (index+piece.size() > arr.size()) return false;
        for (int i = 0;i< piece.size();i++){
            if (arr[index+i] != piece[i]) return false;
        }
        return true;
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


