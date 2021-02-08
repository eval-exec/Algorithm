#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ']') {
                string ret = getstring(st);
                for (char r : ret) {
                    st.push(r);
                }
            } else {
                st.push(c);
            }
        }
        string ret;
        while (!st.empty()) {
            char c = st.top();
            st.pop();

            ret.push_back(c);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

private:
    string getstring(stack<char> &st) {
        string ret;
        while (st.top() != '[') {
            char c = st.top();
            st.pop();

            ret.push_back(c);
        }
        st.pop();

        reverse(ret.begin(), ret.end());

        int C = 0;
        int count = 0;
        while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
            int n = st.top() - '0';
            st.pop();
            count += n * mm(C);
            C++;
        }
        string tmp = ret;
        while (count > 1) {
            tmp += ret;
            count--;
        }
        return tmp;
    }

    int mm(int c) {
        if (c == 0) {
            return 1;
        }
        return pow(10, c);
    }
};

struct T {
    string s;
    string expect;

};

TEST(Solution, test) {
    T ts[] = {
            {"3[a]"},
            {"3[ab]"},
            {"ab3[a]"},
            {"ab13[a19[q]]"},
            {"ab3[ab2[q]xxx]"},
    };


    for (T t : ts) {
        Solution solution;
        cout << t.s << endl;
        cout << solution.decodeString(t.s) << "\n\n";
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


