

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rets;
        for (int i = 0; i < numRows; i++) {
            vector<int> ret(i + 1);
            for (int j = 0; j <= i; j++) {
                ret[j] = cal(rets, i, j);
            }
            rets.push_back(ret);
        }
        return rets;
    }

private:
    int cal(vector<vector<int>> &rets, int now, int i) {
        if (i == 0 || i == now) {
            return 1;
        }
        return rets[now - 1][i - 1] + rets[now - 1][i];

    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


