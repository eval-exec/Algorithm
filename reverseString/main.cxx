
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
ass Solution {
    public:
        void reverseString(vector<char>& s) {
            int len = s.size();
            for (int i= 0;i< len/2;i++){
                s[i]+= s[len-1-i];
                s[len-1-i] = s[i] -s[len-1-i];
                s[i] -= s[len-1-i];

            }
        }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


