
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (K == 1) {
            return 0;
        }
        int k = 0;
        if (K & 1) {
            k = K / 2 + 1;
        } else {
            k = K / 2;
        }
        int last = kthGrammar(N - 1, k);
        if (last == 0) {
            if (K & 1) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (K & 1) {
                return 1;
            } else {
                return 0;
            }
        }
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


