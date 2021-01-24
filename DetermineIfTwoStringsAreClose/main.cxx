#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2) return false;
        array<int, 26> a1 = {0};
        array<int, 26> a2 = {0};
        bitset<26> b1, b2;
        for (int i = 0; i < len1; i++) {
            b1.set(word1[i] - 'a');
            a1[word1[i] - 'a']++;

            b2.set(word2[i] - 'a');
            a2[word2[i] - 'a']++;
        }
        if (b1 != b2) return false;
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < 26; i++) {
            if (a1[i] != 0) {
                v1.push_back(a1[i]);
                v2.push_back(a2[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};

struct T {
    string word1;
    string word2;
    bool expect;

};

TEST(Solution, test) {
    T ts[] = {
        {
            "cabbba",
            "abbccc",
            true

        },

    };

    for (T &t : ts) {
        Solution solution;
        EXPECT_EQ(solution.closeStrings(t.word1, t.word2), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


