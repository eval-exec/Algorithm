#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
    public:
        int numDifferentIntegers(string word) {
            unordered_set<string> nums;
            bool started = false;
            string num;
            for (char c : word){
                if (!started){
                    if (c >= '0' && c <= '9'){
                        started = true;
                        num.push_back(c);
                    }
                }else{
                    if (c >= '0' && c <= '9'){
                        num.push_back(c);
                    }else{
                        started = false;
                        int z = 0;
                        while(str[z] == '0') z++;
                        num.erase(0,z);
                        nums.insert(num);
                        num.clear();
                    }
                }
            }
            if (!num.empty()){
                int z = 0;
                while(str[z] == '0') z++;
                num.erase(0,z);
                nums.insert(num);
            }
            return nums.size();
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


