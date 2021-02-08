#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &s1, const string s2) -> bool {
            return s1.size() > s2.size();
        });
        vector<int> bits;
        for (int i = 0; i < words.size(); i++) {
            bitset<26 * 1000> sum;
            for (int j = 0; j < words[i].size(); j++) {
                bits[i] |= (1 << (words[i][j] - 'a' + 1));
            }
        }

        int max_p = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((bits[i] & bits[j]) == 0) {
                    max_p = max(max_p, int(words[i].size() * words[j].size()));
                    if (max_p >= words[i].size() * words[i].size()) return max_p;
                }
            }
        }
        return max_p;
    }
};

class Solution1 {
  public:
    int maxProduct(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &s1, const string s2) -> bool {
            return s1.size() < s2.size();
        });
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

            for (int j = words.size() - 1; j > i; j--) {
                if (ss.count(j) != 0) continue;
                max_p = max(max_p, int(words[i].size() * words[j].size()));
                break;
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
    ofstream f;
    f.open("tmp.txt");

    for (int i = 0; i < 1000; i++) {
        int word_len = rand() % 1000;
//        int word_len = 4;
        string word;
        word.resize(word_len);
        for (int j = 0; j < word_len; j++) {
            int w = rand() % 26;
            word[j] = char('a' + w);
        }
        f << '"' << word << '"' << ",";
    }
    f.flush();
    f.close();

    return RUN_ALL_TESTS();
}


