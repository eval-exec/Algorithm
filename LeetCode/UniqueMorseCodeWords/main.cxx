#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        set<string> ss;
        for (auto &word: words) {
            string ret;
            for (char &c: word) {
                ret += conv(c);
            }
            ss.insert(ret);
        }
        return ss.size();
    }

private:
    string conv(const char &c) {
        return mos[c - 'a'];
    }


    vector<string> mos = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                          "....", "..", ".---", "-.-", ".-..", "--",
                          "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                          "..-", "...-", ".--", "-..-", "-.--", "--.."};
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


