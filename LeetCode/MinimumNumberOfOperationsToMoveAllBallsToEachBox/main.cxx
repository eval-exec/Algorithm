#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());

        int load = 0;
        int n = 0;
        for (int i = 0 ;i < boxes.size();i++){
            load += n;
            ans[i] += load;
            n += num(boxes[i]);
        }
        n=0;
        load = 0;
        for (int i = boxes.size()-1 ;i >=0 ;i--){
            load += n;
            ans[i] = load;
            n += num(boxes[i]);
        }
        return ans;
    }
private:
    int num(char c){
        if (c == '1') return 1;
        return 0;
    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
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


