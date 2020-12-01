#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        return wordBreak(s, 0, wordDict);
    }

private:
    set<int> memo;

    bool wordBreak(const string &s, int index, const vector<string> &wordDict) {
        if (index == s.size()) return true;
        if (memo.count(index) > 0) return false;

        bool ok = false;
        for (const string &word: wordDict) {
            if (sEqual(s, index, word)) {
                if (wordBreak(s, index + word.size(), wordDict)) {
                    ok = true;
                } else {
                    memo.insert(index + word.size());
                }
            }
        }
        return ok;
    }

    bool sEqual(const string &str, int index, const string &target) {
        if (target.size() + index > str.size()) return false;

        for (int i = 0; i < target.size(); i++) {
            if (str[index + i] != target[i]) {
                return false;
            }
        }
        return true;
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


