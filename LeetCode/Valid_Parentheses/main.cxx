
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (int i = 0; i < s.size(); i++) {
            if (ss.empty()) {
                ss.push(s[i]);
                continue;
            }

            if (ok(ss.top(), s[i])) {
                ss.pop();
                continue;
            }

            if (isLeft(s[i])) {
                ss.push(s[i]);
                continue;
            }
            return false;
        }
        return ss.empty();
    }

private:
    bool isLeft(char a) {
        return
                a == '(' ||
                a == '{' ||
                a == '[';
    }

    bool ok(char a, char b) {
        return
                a == '(' && b == ')' ||
                a == '{' && b == '}' ||
                a == '[' && b == ']';
    }
};

struct T {
    string s;
    bool expect;
};

TEST(Solution, isValid) {
    T ts[] = {
            {{"()"},            true,},
            {{"()[]"},          true,},
            {{"()[]{}"},        true,},
            {{"()[]{()}"},      true,},
            {{"(()())[]{()}"},  true,},
            {{"(]()())[]{()}"}, false,},
            {{"(()())[]{()]}"}, false,},
    };
    Solution solution;
    for (T t : ts) {
        EXPECT_EQ(solution.isValid(t.s), t.expect);
    }
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


