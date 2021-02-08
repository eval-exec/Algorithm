#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    struct index {
        int words_idx;
        int word_idx;
        index(int i1, int i2) {
            words_idx = i1;
            word_idx = i2;
        }
    };
  public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int count = 0;
        unordered_multimap<char, index> memo;
        for (int i = 0; i < words.size(); i++) {
            memo.insert({words[i][0], {i, 0}});
        }

        for (const char &c :S) {
            const auto &rs = memo.equal_range(c);
            vector<unordered_multimap<char, index>::iterator> dels;
            vector<unordered_multimap<char, index>::iterator> upds;
            for (auto it = rs.first; it != rs.second; it++) {
                const string &now_word = words[it->second.words_idx];
                if (now_word.size() == it->second.word_idx + 1) {
                    dels.push_back(it);
                    count++;
                } else {
                    upds.push_back(it);
                }
            }
            for (auto d : dels) {
                memo.erase(d);
            }
            for (auto u : upds) {
                int w_idx = u->second.words_idx;
                int idx = u->second.word_idx + 1;
                const char c = words[u->second.words_idx][idx];
                memo.erase(u);
                memo.insert({c, {w_idx, idx}});
            }
        }

        return count;
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


