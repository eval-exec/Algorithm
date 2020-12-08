#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int len = nums.size();
        if (len == 0) return false;
        
        unordered_map<int,int> mm;
        int sum=0;
        mm[0]=-1;
        
        sum += nums[0];
        if (k !=0){
            sum = sum % k;
        }
        if (mm.find(sum) == mm.end()){
            mm[sum] = 0;
        }

        for (int i = 1; i < len; i++) {
            sum += nums[i];
            if (k != 0){
                sum = sum % k;
            }
            auto f = mm.find(sum);
            if (f != mm.end()){
                cout << f->second << endl;
                if (i - f->second >=2) return true;
            }else{
                mm[sum] = i;
            }
        }
        return false;
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


