#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        string first = strs[0];
        int firstLen = first.size();
        vector<int> arr(firstLen);
        int longIndex = 0;
        int longCount = firstLen;
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size() && j < firstLen; j++) {
                if (strs[i][j] != first[j]) {
                    if (j < longCount) {
                        longIndex = i;
                        longCount = j;
                    }
                }
            }
            if (strs[i].size() < longCount) {
                longIndex = i;
                longCount = strs[i].size();
            }

        }
        string ret = strs[longIndex];
        ret.resize(longCount);
        return ret;
    }
};


struct T {
    vector<string> strs;
    string result;
};

TEST(Solution, test) {
    T ts[] = {
            {
                    .strs={"flower", "flow", "flight"},
                    .result="fl",
            },
            {
                    .strs={"", "flow", "flight"},
                    .result="",
            },
            {
                    .strs={"abcd"},
                    .result="abcd",
            },
            {
                    .strs={"abcdf", "abcde"},
                    .result="abcd",
            },
            {
                    .strs={"ab", "a"},
                    .result="a"
            },
            {
                    .strs = {"abccd", "ab"},
                    .result = "ab",
            },
            {
                    .strs = {"ab", "abcd"},
                    .result = "ab",
            },

    };

    Solution solution;

    for (
        T t
            : ts) {
        cout <<
             endl;
        EXPECT_EQ(solution.longestCommonPrefix(t.strs), t.result);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


