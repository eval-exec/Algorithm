
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int last = prices[0];
        for (int n : prices){
            if ( n > last){
                max+= n-last;
            }
            last = n;
        }
        return max;
        
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


