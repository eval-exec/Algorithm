#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> st;
        int i = 0;
        int j = 0;
        while (i < pushed.size() && j < popped.size()) {
            if (st.empty()) {
                st.push(pushed[i]);
                continue;
            }
            if (st.top() == popped[j]) {
                st.pop();
                j++;
            } else {
                st.push(pushed[i]);
                i++;
            }
        }
        if (i == pushed.size() && j == popped.size()) return true;
        if (i == pushed.size()) {
            while (!st.empty() && j < popped.size()) {
                if (st.top() != popped[j]) return false;
                st.pop();
                j++;
                if (j == popped.size()) return true;
            }
            return false;
        }
        return true;
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


