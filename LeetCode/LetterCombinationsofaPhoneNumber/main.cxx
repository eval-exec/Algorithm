#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        auto f = memo.find(digits);
        if (f != memo.end()) {
            return f->second;
        }
        vector<string> rets;
        if (digits.size() == 1) {
            rets = keys[digits[0]];
        } else {
            auto tails = letterCombinations(digits.substr(1));

            for (const auto &c1 : keys[digits[0]]) {
                for (const auto &tail : tails) {
                    rets.push_back(c1 + tail);
                }
            }
        }
        memo[digits] = rets;
        return rets;
    }
  private:
    unordered_map<char, vector<string>> keys = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };
    unordered_map<string, vector<string>> memo;
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
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


