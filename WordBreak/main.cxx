#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution2 {
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


class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (i > 0) {
                if (!dp[i - 1]) continue;
            }

            for (const string &word : wordDict) {
                if (s.compare(i, word.size(), word, 0) == 0) {
                    printf("%d %s\n", i, word.c_str());
                    dp[i + word.size() - 1] = true;
                }
            }
        }

        for (int i : dp) {
            cout << i << " ";
        }
        cout << endl;

        return dp[s.size() - 1];
    }
};


struct T {
    string s;
    vector<string> wordDist;
    bool expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    .s="leetcode",
                    .wordDist={"leet", "code"},
                    .expect=true,
            },
            {
                    .s="catsandog",
                    .wordDist={"cats", "dog", "sand", "and", "cat"},
                    .expect = false,
            }

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.wordBreak(t.s, t.wordDist), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


