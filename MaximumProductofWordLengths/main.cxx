#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<string> &words) {
        vector<set<int>> memo(26);
        for (int i = 0; i < words.size(); i++) {
            for (const char &c : words[i]) {
                memo[c - 'a'].insert(i);
            }
        }

        int max_p = 0;

        for (int i = 0; i < words.size(); i++) {
            set<int> ss;
            for (const char &c : words[i]) {
                auto s2 = memo[c - 'a'];
                ss.insert(s2.begin(), s2.end());
            }
            for (int j = 0; i < words.size() && j != i && ss.count(j) == 0; j++) {
                max_p = max(max_p, int(words[i].size() * words[j].size()));
            }
        }
        return max_p;
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


