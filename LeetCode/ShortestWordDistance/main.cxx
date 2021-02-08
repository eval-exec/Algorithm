#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int min_dis = INT_MAX;
        int i1 = -1, i2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                i1 = i;
            } else if (words[i] == word2) {
                i2 = i;
            }
            if (i1 != -1 && i2 != -1) {
                min_dis = min(min_dis, abs(i1 - i2));
            }
        }
        return min_dis;
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


