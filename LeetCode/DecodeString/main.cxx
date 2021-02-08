#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
private:
    const char start = '[';
    const char end = ']';

    bool isDigital(char c) {
        return c >= '0' && c <= '9';
    }

public:
    string decodeString(string s) {
        stack<char> ss;

        for (char ch : s) {
            if (ch != end) {
                ss.push(ch);
                continue;
            }

            string tmp;
            while (ss.top() != start) {
                tmp.push_back(ss.top());
                ss.pop();
            }
            ss.pop();

            string cha;
            while (!ss.empty() && isDigital(ss.top())) {
                cha.push_back(ss.top());
                ss.pop();
            }
            reverse(cha.begin(),cha.end());
            int n = atoi(cha.c_str());

            reverse(tmp.begin(), tmp.end());

            string del = tmp;
            for (int i = 0; i < n - 1; i++) {
                tmp += del;
            }
            for (char c : tmp) {
                ss.push(c);
            }
        }
        string ret;
        while (!ss.empty()) {
            ret.push_back(ss.top());
            ss.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


struct T {
    string s;
    string expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    "3[a]2[bc]",
                    "aaabcbc"
            },
            {
                "12[a]",
                "aaaaaaaaaaaa"
            }

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.decodeString(t.s), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


