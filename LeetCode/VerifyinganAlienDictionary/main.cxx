#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    bool isAlienSorted(vector<string> &words, string order) {
        unordered_map<char, int> orders;
        for (int i = 0; i < order.size(); i++) {
            orders[order[i]] = i;
        }
        vector<string> procw(words);
        sort(procw.begin(), procw.end(), [&](const string &s1, const string &s2) -> bool {
            int len = min(s1.size(), s2.size());
            for (int i = 0; i < len; i++) {
                if (orders[s1[i]] < orders[s2[i]])return true;
                if (orders[s1[i]] > orders[s2[i]])return false;
            }
            if (s1[len - 1] == s2[len - 1]) {
                return s1.size() <= s2.size();
            }
            return true;
        });
        return words == procw;
    }
};

struct T {
    vector<string> words;
    string order;
};

TEST(Solution, test) {
    T ts[] = {
//        {
//
//            .words={"hello", "leetcode"},
//            .order="hlabcdefgijkmnopqrstuvwxyz",
//
//        },
//        {
//            .words={"iekm", "tpnhnbe"},
//            .order="loxbzapnmstkhijfcuqdewyvrg",
//        }
        {
            .words={"app", "apple"},
            .order="abcdefghijklmnopqrstuvwxyz",
        }
    };

    for (T t : ts) {
        Solution solution;
        cout << solution.isAlienSorted(t.words, t.order) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


