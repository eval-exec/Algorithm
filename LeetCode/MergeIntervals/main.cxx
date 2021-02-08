#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> rets;
        stack<int> st;


        for (auto &interval : intervals) {
            if (st.empty()) {
                st.push(interval[0]);
                st.push(interval[1]);
                continue;
            }
            if (st.top() < interval[0]) {
                int r2 = st.top();
                st.pop();
                int r1 = st.top();
                st.pop();
                rets.push_back({r1, r2});
                st.push(interval[0]);
                st.push(interval[1]);
            } else if (st.top() == interval[0]) {
                st.pop();
                st.push(interval[1]);
            } else {
                int r2 = st.top();
                st.pop();
                int r1 = st.top();
                st.pop();

                st.push(min(r1, interval[0]));
                st.push(max(r2, interval[1]));
            }
        }
        int r2 = st.top();
        st.pop();
        int r1 = st.top();
        st.pop();
        rets.push_back({r1, r2});

        return rets;

    }
};


struct T {
    vector<vector<int>> intervals;
    vector<vector<int>> expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{{1, 3}, {2, 6}, {8, 10}, {15, 18}, {14, 19}, {25, 25}, {28, 34}}},
                    {{{1, 6}, {8, 10}, {14, 19}, {25, 25}, {28, 34}}}
            },

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.merge(t.intervals), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


