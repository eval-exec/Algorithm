#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, len = s.size();

        for (int i = 0; i <= len; i++) {
            if (s[i] == ' ' || i == len) {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        while (*s.begin() == ' ') {
            s.erase(s.begin(),s.begin() + 1);
        }
        while (*(s.end() - 1) == ' ') {
            s.pop_back();
        }
        return s;
    }
};

TEST(Solution, reverseWords) {
    Solution solution;
    const string &basicString = solution.reverseWords("Let's take LeetCode contest");
    cout << basicString << endl;
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


