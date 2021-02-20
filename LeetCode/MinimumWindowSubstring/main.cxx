#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        array<int, 52> ta = {0};
        for (char c : t) {
            ta[hash(c)]++;
        }
        int i = 0, j = 0;
        int ret_len = s.size();
        int ret_i = 0;
        array<int, 52> sa = {0};

        bool exist = false;
        for (; j < s.size(); j++) {
            sa[hash(s[j])]++;
            if (contain(sa, ta) == -1) continue;

            exist = true;

            while (contain(sa, ta) >= 0) {
                if (j - i + 1 < ret_len) {
                    ret_len = j - i + 1;
                    ret_i = i;
                }
                sa[hash(s[i])]--;
                i++;
            }
        }
        if (!exist) return "";
        return s.substr(ret_i, ret_len);
    }
  private:
    int hash(const char &c) {
        if (c >= 'a') {
            return 26 + c - 'a';
        }
        return c - 'A';
    }
    int contain(const array<int, 52> &l, const array<int, 52> &r) {
        if (l == r) return 0;
        for (int i = 0; i < 52; i++) {
            if (l[i] < r[i]) return -1;
        }
        return 1;
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


