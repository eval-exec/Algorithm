
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int n = 0;
        int i = 0;
        int last = 0;
        while (i <= len - 1) {
            if (valid(s[i])) {
                s[n] = s[i];
                last = n;
                n++;
            } else {
                if (n != 0) {
                    if (valid(s[n - 1])) {
                        s[n] = ' ';
                        n++;
                    }
                }
            }
            i++;
        }

        s.erase(s.begin() + last + 1, s.end());

        reverse(s.begin(), s.end());
        len = s.size();
        int now = 0;
        for (int i = 0; i <= len; i++) {
            if (!valid(s[i]) || i == len) {
                reverse(s.begin() + now, s.begin() + i);
                now = i + 1;
            }
        }
        return s;
    }

private:
    bool valid(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }
};

void print(vector<int> vs) {
    for (int n: vs) {
        cout << n << " ";
    }
    cout << endl;
}

struct T {
    string s;
};
TEST(Solution, reverseWords) {
    Solution solution;

    T ts[] = {
            {{" hello world "}},
            {{" hello  world  "}},
            {{"the sky is blue"}},
            {{"   the sky is blu      e        "}},
            {{"a"}},
            {{" a"}},
            {{"a "}},
            {{" a "}},
            {{"a b "}},
            {{" a b "}},
            {{"a b"}},
            {{" a b"}},
            {{"a  b"}},
    };

    for (T t : ts) {
        cout << "." << t.s << "." << endl;
        string ret = solution.reverseWords(t.s);
        cout << "." << ret << "." << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


