#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string last = countAndSay(n - 1);
        int l = 0;

        string ret;
        char tmp = last[0];
        int count = 0;
        for (int i = 0; i < last.size(); i++) {
            if (last[i] != tmp) {
                ret += to_string(count);
                ret += tmp;
                tmp = last[i];
                count = 1;
                continue;
            }
            count++;
        }

        if (count != 0) {
            ret += to_string(count);
            ret += tmp;
        }

        return ret;
    }
};


struct T {
    int n;
    string result;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    1,
                    "1"
            },
            {
                    2,
                    "11"
            },
            {
                    3,
                    "21"
            },
            {
                    4,
                    "1211",
            },
            {
                    5,
                    "111221",
            },
            {
                    6,
                    "312211",
            },
            {
                    7,
                    "13112221",
            },
            {
                    8,
                    "1113213211",
            },

    };

    Solution solution;

    for (T t : ts) {
        cout << endl;
        cout << t.n << endl;
        EXPECT_EQ(solution.countAndSay(t.n), t.result);
        cout << t.result << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


