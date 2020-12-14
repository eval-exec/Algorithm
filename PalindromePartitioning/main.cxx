#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        if (s.size() == 1) return {{s}};
        {
            auto f = mm.find(s);
            if (f != mm.end()) {
                return f->second;
            }
        }
        vector<vector<string>> rets;
        for (int i = 1; i <= s.size(); i++) {
            if (isPalindrom(s.substr(0, i))) {
                if (i != s.size()) {
                    auto rems = partition(s.substr(i));
                    for (auto &rem : rems) {
                        rem.insert(rem.begin(), s.substr(0, i));
                        rets.push_back(rem);
                    }
                } else {
                    rets.push_back({s});
                }
            }
        }
        mm[s] = rets;
        return rets;
    }
  private:
    map<string, vector<vector<string>>> mm;
    bool isPalindrom(const string &str) {
        if (str.size() == 1) return true;
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - 1 - i]) return false;
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


