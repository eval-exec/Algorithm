
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int len = asteroids.size();
        stack<int> mm;
        mm.push(asteroids[0]);
        for (int i = 1; i < len; i++) {
            int now = asteroids[i];
            colission(mm, now);
        }

        int mlen = mm.size();
        vector<int> ret(mlen);

        while (!mm.empty()) {
            mlen--;
            int top = mm.top();
            ret[mlen] = top;
            mm.pop();
        }
        return ret;
    }

    void colission(stack<int> &mm, int now) {
        if (mm.empty()) {
            mm.push(now);
            return;
        }

        int top = mm.top();
        if (now > 0 || top < 0) {
            mm.push(now);
            return;
        }
        if (top == -now) {
            mm.pop();
            return;
        }

        if (top < -now) {
            mm.pop();
            return colission(mm, now);
        }
    }
};

struct T {
    vector<int> asterios;
    vector<int> survivors;
};

void print(vector<int> &ns) {
    for (int n:ns) {
        cout << n << " ";
    }
    cout << endl;
}

TEST(Soluton, solution) {
    Solution solution;
    T ts[] = {
            {
                    {{5,  10, -5}},
                    {{5,  10}},
            },
            {
                    {{8,  -8}},
                    {},
            },
            {
                    {{10, 2,  -5}},
                    {{10}},
            },
            {
                    {{-2, -1, 1, 2}},
                    {{-2, -1, 1, 2}},
            },
            {
                    {{1,  -1, 1}},
                    {{1}},
            },
    };
    for (T t : ts) {
        print(t.asterios);
        print(t.survivors);
        vector<int> ret = solution.asteroidCollision(t.asterios);
        print(ret);
        cout << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


