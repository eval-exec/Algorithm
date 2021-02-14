#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int minOperations(string s) {
        if (s.size() <= 1) return 0;
        int count1 = 0,count2 = 0;
        if (s[0]== '0'){
            count1 = cal('0',s);
            count2 = cal('1',s) + 1;
        }else{
            count1 = cal('0',s) + 1;
            count2 = cal('1',s);
        }
        return min(count1,count2);
    }
private:
    int cal(char f,const string &s){
        int count = 0;
        for (int i = 1;i < s.size();i++){
            if (s[i] == f){
                count++;
                if (f=='0'){
                    f = '1';
                }else{
                    f = '0';
                }
            }else{
                f = s[i];
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


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


