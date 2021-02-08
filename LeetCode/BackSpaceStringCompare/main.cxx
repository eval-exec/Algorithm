#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
    const char bang = '#';
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        while (true) {
            {
                int sn = 0;
                while (i >= 0 && (S[i] == bang || sn > 0)) {
                    if (S[i] == bang) {
                        sn++;
                    } else {
                        sn--;
                    }
                    i--;
                }
            }

            {
                int tn = 0;
                while (j >= 0 && (T[j] == bang || tn > 0)) {
                    if (T[j] == bang) {
                        tn++;
                    } else {
                        tn--;
                    }
                    j--;
                }
            }
            if (i < 0 || j < 0) break;

            if (S[i] != T[j]) return false;

            i--;
            j--;
        }
        return i == -1 && j == -1;
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


