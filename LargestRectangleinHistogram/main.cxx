#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        int maxAre = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];

                st.pop();

                int w = i;

                if (!st.empty()) w = i - 1 - st.top();
                maxAre = max(maxAre, w * h);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = heights.size();
            if (!st.empty()) w = heights.size() - 1 - st.top();
            maxAre = max(maxAre, w * h);
        }
        return maxAre;
    }
};


struct T {
    vector<int> heights;
    int expect;

};



TEST(Solution, test) {
    T ts[] = {
            {
                    {{2,     4,     6,     4,    5,     6,    7,     6,     4,    2,     8,     4}},
                    32
            },
            {
                    {{2,     1,     5,     6,    2,     3}},
                    10,
            },
            {
                    {{0}},
                    0,
            },
            {
                    {{1}},
                    1,
            },
            {
                    {{10177, 20834, 26894, 1130, 19350, 9679, 32139, 13839, 1493, 16100, 12207, 20610, 22270, 30580, 5893, 29453, 25185, 16649, 31349, 22100, 31132, 21099, 29932, 367, 16187, 3227, 27343, 8954, 735, 10756, 2642, 22698, 24961, 14371, 24358, 8706, 2714, 20457, 31976, 31304, 4525, 11022, 25601, 15945, 26743, 196, 1375, 24445, 29473, 17110, 9751, 11017, 22854, 12345, 19532, 4689, 12645, 23157, 2921, 31815, 268, 26282, 22138, 27979, 24008, 7139, 5370, 13458, 16864, 17518, 3916, 27685, 5151, 22041, 24408, 4969, 20332, 26319, 16443, 28547, 1084, 8676, 21075, 1910, 15169, 8799, 8867, 2879, 21790, 22091, 13241, 5339, 25544, 10508, 20421, 16903, 9206, 27959, 14945, 2685}},
                    133192,
            }
    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.largestRectangleArea(t.heights), t.expect);
        cout << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


