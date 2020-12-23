#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int nextGreaterElement(int n) {
        vector<int> ns;
        int N = n;
        while (N > 0) {
            ns.push_back(N % 10);
            N /= 10;
        }
        reverse(ns.begin(), ns.end());
        bool found = false;
        int max_v = ns[ns.size() - 1];
        int i = ns.size() - 2;
        for (; i >= 0; i--) {
            if (ns[i] < max_v) {
                found = true;
                break;
            }
            if (ns[i] > max_v) max_v = ns[i];
        }
        if (!found) return -1;
        int max_i = ns.size() - 1;
        for (int j = max_i; j > i; j--) {
            if (ns[j] > ns[i]) {
                max_i = j;
                break;
            }
        }
        long ret = 0;
        swap(ns[i], ns[max_i]);
        sort(ns.begin() + i + 1, ns.end());
        int cc = 0;
        for (int j = ns.size() - 1; j >= 0; j--, cc++)
            ret += ns[j] * pow(10, cc);
        long M = long(INT_MAX);
        return ret > M ? -1 : ret;
    }
};

struct T {
    int n;
    int e;

};

TEST(Solution, test) {
    T ts[] = {
        {
            12,
            21
        },
        {
            21,
            -1
        }

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.nextGreaterElement(t.n), t.e);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


