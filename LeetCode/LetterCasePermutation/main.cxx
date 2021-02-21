#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<string> letterCasePermutation(string S) {
        return cal(S);
    }
  private:
    unordered_map<string, vector<string>> memo;
    vector<string> cal(string S) {
        if (S.empty()) return {};
        auto f = memo.find(S);
        if (f != memo.end()) {
            return f->second;
        }
        vector<string> rets;
        if (S.size() == 1) {
            for (auto ne :trans(S[0])) {
                string s;
                s.push_back(ne);
                rets.push_back(s);
            }
        } else {
            for (auto ne :trans(S[0])) {
                for (auto sub :cal(S.substr(1))) {
                    rets.push_back(ne + sub);
                }
            }
        }
        memo[S] = rets;
        return rets;
    }
    vector<char> trans(char c) {
        if (c >= '0' && c <= '9') {
            return {c};
        } else if (c >= 'a' && c <= 'z') {
            return {c, char(c - ('a' - 'A'))};
        } else {
            return {c, char(c + ('a' - 'A'))};
        }
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


