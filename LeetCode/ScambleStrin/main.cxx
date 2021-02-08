#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        int length = s1.size();
        vector<vector<vector<bool>>> dp(length + 1, vector<vector<bool>>(length, vector<bool>(length)));
        // dp[index1][index2][lenth]
        for (int len = 1; len <= length; len++) {
            for (int i1 = len - 1; i1 < length; i1++) {
                for (int i2 = len - 1; i2 < length; i2++) {
                    bool ok = false;
                    if (len == 1) {
                        ok = s1[i1] == s2[i2];
                    } else if (i1 > 0 && i2 > 0 && len == 2) {
                        ok = s1[i1] == s2[i2] && s1[i1 - 1] == s2[i2 - 1] ||
                            s1[i1] == s2[i2 - 1] && s1[i1 - 1] == s2[i2];
                    } else if (i1 > 1 && i2 > 1) {
                        for (int l = 1; l <= len - 1; l++) {
                            if (dp[l][i1][i2] && dp[len - l][i1 - l][i2 - l] ||
                                dp[l][i1][i2 - len + l] && dp[len - l][i1 - l][i2]) {
                                ok = true;
                            }
                        }
                    }
                    dp[len][i1][i2] = ok;
                }
            }
        }
        return dp[length][length - 1][length - 1];
    }
};

class Solution1 {
  public:
    bool isScramble(string s1, string s2) {
        int length = s1.size();
        vector<vector<vector<bool>>> dp(length, vector<vector<bool>>(length, vector<bool>(length + 1)));
        // dp[index1][index2][lenth]
        for (int len = 1; len <= length; len++) {
            for (int i1 = 0; i1 < length; i1++) {
                for (int i2 = 0; i2 < length; i2++) {
                    bool ok = false;
                    if (len == 1) {
                        ok = s1[i1] == s2[i2];
                    } else if (i1 > 0 && i2 > 0 && len == 2) {
                        ok = s1[i1] == s2[i2] && s1[i1 - 1] == s2[i2 - 1] ||
                            s1[i1] == s2[i2 - 1] && s1[i1 - 1] == s2[i2];
                    } else if (i1 > 1 && i2 > 1) {
                        for (int l = 1; l <= len - 1; l++) {
                            if (dp[i1][i2][l] && dp[i1 - l][i2 - l][len - l] ||
                                dp[i1][i2 - len + l][l] && dp[i1 - l][i2][len - l]) {
                                ok = true;
                            }
                        }
                    }
                    dp[i1][i2][len] = ok;
                }
            }
        }
        return dp[length - 1][length - 1][length];
    }
};

class Solution_recursion {
  public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1, s2, 0, 0, s1.size());
    }
  private:
    typedef tuple<int, int, int> KeyTriple;
    map<KeyTriple, int> memo;
    bool isScramble(const string &s1, const string &s2, int i1, int i2, int len) {
        auto f = memo.find({i1, i2, len});
        if (f != memo.end()) {
            return f->second;
        }
        if (len == 1) {
            return s1[i1] == s2[i2];
        }
        if (len == 2) {
            return (s1[i1] == s2[i2] && s1[i1 + 1] == s2[i2 + 1]) || (s1[i1 + 1] == s2[i2] && s1[i1] == s2[i2 + 1]);
        }
        for (int l = 1; l <= len - 1; l++) {
            // 0 1 2
            if (isScramble(s1, s2, i1, i2, l) &&
                isScramble(s1, s2, i1 + l, i2 + l, len - l) ||
                isScramble(s1, s2, i1, i2 + len - l, l) &&
                    isScramble(s1, s2, i1 + l, i2, len - l)) {
                memo[{i1, i2, len}] = true;
                return true;
            }
        }
        memo[{i1, i2, len}] = false;
        return false;
    }
};;

struct T {
    string a;
    string b;
    bool expect;

};

TEST(Solution, test) {
    T ts[] = {
//        {"fewafewa",
//         "fewafawe",
//         true
//        },
        {
            "ejsejxhmgobegp",
            "ggjeohbpejemsx",
            false
        },
//        {
//            "ccabcbabcbabbbbcbb",
//            "bbbbabccccbbbabcba",
//            true,
//        }

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.isScramble(t.a, t.b), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


