#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1.size() == 1 && num(num1[0]) == 0 || num2.size() == 1 && num(num2[0]) == 0) return "0";
        if (num2.size() > num1.size()) swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i2 = 0; i2 < num2.size(); i2++) {
            int n2 = num(num2[i2]);
            for (int i1 = 0; i1 < num1.size(); i1++) {
                int n1 = num(num1[i1]);
                int v = n1 * n2;
                add(i2 + i1, v);
            }
        }
        string val;
        for (auto it = ret.rbegin(); it < ret.rend(); it++) {
            val.push_back(char(*it + '0' - 0));
        }
        return val;
    }
  private:
    vector<int> ret;
    void add(int index, int value) {
        if (value == 0) return;
        while (index >= ret.size()) {
            ret.push_back(0);
        }
        ret[index] += value;
        int v = ret[index];
        ret[index] = v % 10;
        int c = (v - ret[index]) / 10;
        if (c > 0) add(index + 1, c);
    }
    int num(const char &c) {
        return c - '0';
    }
};

struct T {
    string num1;
    string num2;
    string e;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .num1="2",
            .num2="3",
            .e="6",
        },
        {
            .num1="12",
            .num2="10",
            .e="120",
        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.multiply(t.num1, t.num2), t.e);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


