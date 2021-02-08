#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ret;
        for (int i =0;i< command.size();i++){
            if (command[i] =='G'){
                ret+="G";
            }else if(command[i] == '('){
                if (command[i+1] == 'a'){
                    ret+="al";
                    i+=2;
                }else{
                    ret+="o";
                    i+=1;
                }
            }
        }
        return ret;
        
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


