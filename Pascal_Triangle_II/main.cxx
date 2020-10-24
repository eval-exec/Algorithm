
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        for (int i = 0; i <= rowIndex; i++) {
            last = gen(last, i);
        }
        return last;

    }

    vector<int> gen(const vector<int> &last, int index) {
        if (index == 0) {
            return {1};
        }
        int mid = (index) / 2;
        vector<int> ret(index + 1);
        for (int i = 0; i <= mid; i++) {
            if (i == 0) {
                ret[i] = 1;
                ret[index - i] = ret[i];
            } else {
                ret[i] = last[i - 1] + last[i];
                ret[index - i] = ret[i];
            }
        }
        return ret;

    }
};

void print(vector<int> vs) {
    for (int n: vs) {
        cout << n << " ";
    }
    cout << endl;
}

struct T {
    int rowIndex;
    vector<int> expect;
};

TEST(Solution, getRow) {
    Solution solution;
    T ts[] = {
            {
                    1,
                    {{1, 1}},
            },
            {
                    2,
                    {{1, 2, 1}},
            },
            {
                    3,
                    {{1, 3, 3,  1}},
            },
            {
                    4,
                    {{1, 4, 6,  4,  1}},
            },
            {
                    5,
                    {{1, 5, 10, 10, 5, 1}},
            },
    };

    for (T t : ts) {
        vector<int> row = solution.getRow(t.rowIndex);
        print(row);
        print(t.expect);
        EXPECT_EQ(t.expect,row);
    }

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


