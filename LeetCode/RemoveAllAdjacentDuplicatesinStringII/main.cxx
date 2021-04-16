#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/*
 * ps
 */


class Solution {
  public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char c : s) {
            if (st.empty()) {
                st.push(make_pair(c, 1));
            } else {
                auto top = st.top();
                if (top.first == c) {
                    top.second++;
                    st.pop();
                    if (top.second != k) {
                        st.push(top);
                    }
                } else {
                    st.push(make_pair(c, 1));
                }
            }
        }
        string ret;
        while (!st.empty()) {
            auto top = st.top();
            st.pop();

            int n = 0;
            while (n < top.second) {
                n++;
                ret.insert(ret.begin(), top.first);
            }
        }
        return ret;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


