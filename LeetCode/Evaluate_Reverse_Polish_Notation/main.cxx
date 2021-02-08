
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ss;
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (ss.empty()) {
                int i1 = stoi(c);
                ss.push(i1);
                continue;
            }
            if (cals.find(c) == cals.end()) {
                int i1 = stoi(c);
                ss.push(i1);
                continue;
            }

            int r = ss.top();
            ss.pop();

            int l = ss.top();
            ss.pop();
            int result = cal(c, l, r);
            ss.push(result);
        }
        return ss.top();
    }

    int cal(string c, int l, int r) {
        switch (cals[c]) {
            case 1:
                return l + r;
            case 2:
                return l - r;
            case 3:
                return l * r;
            case 4:
                return l / r;
            default:
                throw "panic";
        }
    }

private:
    map<string, int> cals = {
            {"+", 1},
            {"-", 2},
            {"*", 3},
            {"/", 4},
    };
};

struct T {
    vector<string> inputs;
    int expect;
};

TEST(Solution, cal) {
    T ts[] = {
            {
                    {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}},
                    22,
            },
    };
    Solution solution;
    for (T t : ts) {
        int i = solution.evalRPN(t.inputs);
        EXPECT_EQ(i, t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


