#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    string largestMerge(string word1, string word2) {
        if (word1.empty())return word2;
        if (word2.empty())return word1;

        if (word1 < word2) {
            swap(word1, word2);
        }
        return word1[0] + largestMerge(word1.substr(1), word2);
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


