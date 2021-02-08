#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> vv(26);;
        char now = s[0];
        int nowc = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == now) {
                nowc++;
            } else {
                vv[now - 'a'] = max(vv[now - 'a'], nowc);
                now = s[i];
                nowc = 1;
            }
        }
        vv[now - 'a'] = max(vv[now - 'a'], nowc);

        int m = -1;
        for (int n : vv) {
            m = max(m, n);
        }
        return m;
    }
};


struct T {
    string s;
    int n;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    "leetcode",
                    2,
            },
            {
                    "abbcccddddeeeeedcba",
                    5,
            }

    };

    Solution solution;

    for (T t : ts) {
        cout << t.s << endl;
        EXPECT_EQ(solution.maxPower(t.s), t.n);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


