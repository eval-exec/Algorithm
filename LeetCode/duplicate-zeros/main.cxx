
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int len= arr.size();
        for (int i = 0; i < len; i++) {
            if (arr.at(i) == 0) {
                arr.insert(arr.begin() + i, 0);
                i++;
            }
        }
        arr.resize(len);
    }
};

void print(vector<int> nums){
    for(int v:nums){
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution,duplicateZeros){
    Solution solution;
    vector<int> nums = {1,0,2,3,0,4,5,0};
    print(nums);
    solution.duplicateZeros(nums);
    print(nums);
}



int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


