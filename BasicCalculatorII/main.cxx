#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            if (isNum(c)) {
                int len = 0;
                long x = getNum(s, i, len);
                st.push(x);
                i += len - 1;
            } else if (highOpe(c)) {
                i++;
                int len = 0;
                long n2 = getNum(s, i, len);
                i += len - 1;

                bool mul = c == '*';

                long n1 = st.top();
                st.pop();


                if (mul) {
                    st.push(n1 * n2);
                } else {
                    st.push(n1 / n2);
                }
            } else {
                st.push(c);
            }
        }
        if (st.empty()) {
            return 0;
        }
        long ret = st.top();
        st.pop();
        if (st.empty()) {
            return ret;
        }

        if (st.top() == '-') {
            ret = -ret;
        }
        st.pop();
        while (true) {
            if (st.empty()) {
                return ret;
            }

            long n = st.top();
            st.pop();
            if (!st.empty()) {
                if (st.top() == '-') {
                    n = -n;
                }
                st.pop();
            }
            ret += n;
        }
    }

private:
    stack<long> st;

    long getNum(const string &str, int index, int &len) {
        string ret;
        while (index < str.size() && (isNum(str[index]) || str[index] == ' ')) {
            if (str[index] != ' ') {
                ret.push_back(str[index]);
            }
            index++;
            len++;
        }
        long n = atoi(ret.c_str());
        return n;
    }

    bool highOpe(const char &c) {
        return c == '*' || c == '/';
    }

    bool isNum(const char &c) {
        return c >= '0' && c <= '9';
    }
};


struct T {
    string s;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    "1+1",
                    2
            },
            {
                    "1+2*3",
                    7
            },
            {
                    "8  + 7*6/5  + 4+3-2 + 1*2/3  -  4*5",
                    1
            },
            {
                    "8765+8765*8754/7654+765+8765-9876+98765*8765/876-765*876",
                    336516,
            },
            {
                    "1",
                    1
            },
            {
                    " 3+5 / 2 ",
                    5
            }

    };


    for (T &t : ts) {
        Solution solution;
        EXPECT_EQ(solution.calculate(t.s), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


