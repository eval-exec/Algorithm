#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> asLen;
        int start = 0;
        for (int i = 0;i+ 2 < A.size();i++){
            if (A[i] - A[i+1] == A[i+1] - A[i+2]){
                if (i + 3 == A.size()){
                    asLen.push_back(A.size() - start);
                }
                continue;
            }else{
                if (i - start >= 1){
                    asLen.push_back(i-start+2);
                }
                start = i+1;
            }
        }
        int ret = 0;
        for (int n : asLen){ // 1 3 6 10 15
            ret += cal(n);
        }
        return ret;
    }
private:
    unordered_map<int,int> mm;
    int cal(int n){
        if (n == 3){
            return 1;
        }
        auto f = mm.find(n);
        if (f != mm.end()){
            return f->second;
        }
        int ret = n-2 + cal(n-1);
        mm[n] = ret;
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


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


