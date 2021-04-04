#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {

  public:
    bool halvesAreAlike(string s) {
        set<char> vowels = {
            'a',
            'e',
            'i',
            'o',
            'u',
            'A',
            'E',
            'I',
            'O',
            'U',
        };
        int mid = s.size() / 2;
        int na = 0,nb = 0;
        for (int i = 0; i < mid; i++) {
            if (vowels.find(s[i]) != vowels.end()) na++;
        }
        for (int i = mid; i < s.size(); i++) {
            if (vowels.find(s[i]) != vowels.end()) nb++;
        }
        return na == nb;
    }
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


