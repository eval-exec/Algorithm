#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> rets(num + 1);
        rets[0] = 0;
        if (num == 0) return rets;
        rets[1] = 1;
        if (num == 1) return rets;

        int len = 1;
        for (int n = 2; n <= num; n++) {
            int tmp = n & (~(1 << (len - 1)));
            rets[n] = rets[tmp] + 1;
            if (rets[n] == len) len++;
        }
        return rets;
    }
};

class Solution2 {
  public:
    vector<int> countBits(int num) {
        memo[0] = 0;
        memo[1] = 1;
        vector<int> rets(num + 1);
        int len = 1;
        for (int n = 0; n <= num; n++) {
            rets[n] = cal(n, len);
            if (rets[n] == len) len++;
        }
        return rets;
    }
  private:
    int cal(int n, int len) {
        auto f = memo.find(n);
        if (f != memo.end()) return f->second;
//        int tmp = n & (~(1 << (len - 1)));
        int tmp = n - (1 << (len - 1));
        int result = cal(tmp, len - 1) + 1;

        memo[n] = result;
        return result;
    }

    map<int, int> memo;
};

struct T {
    int num;
    vector<int> expect;

};

TEST(Solution, test) {
    T ts[] = {
        {
            2,
            {{0, 1, 1}}

        },
        {
            5,
            {{0, 1, 1, 2, 1, 2}}
        },
        {
            INT_MAX - 1,
            {{0, 1, 1, 2, 1, 2}}
        }

    };

    for (T t : ts) {
        Solution solution;
        auto start = clock();
        EXPECT_EQ(solution.countBits(t.num), t.expect);
        auto end = clock();
        cout << end - start << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


