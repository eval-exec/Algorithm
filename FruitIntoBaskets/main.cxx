#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {

public:
    int totalFruit(vector<int> &tree) {
        int len = tree.size();
        dp_item dp_last = dp_item(1);
        dp_last.mm[tree[0]] = 1;
        int ret = 1;
        for (int i = 1; i < len; i++) {
            int now = tree[i];
            int last = tree[i - 1];
            dp_item dp_now;

            if (now == last) {
                dp_now = dp_item(dp_last.ccount + 1);
                dp_now.mm = dp_last.mm;
                dp_now.mm[now] += 1;
                ret = max(ret, sum(dp_now.mm));
            } else {
                if (dp_last.mm.find(now) != dp_last.mm.end()) {
                    dp_now = dp_item(1);
                    dp_now.mm = dp_last.mm;
                    dp_now.mm[now] += 1;
                    ret = max(ret, sum(dp_now.mm));
                } else { // new key
                    dp_now = dp_item(1);
                    dp_now.mm[now] = 1;
                    dp_now.mm[tree[i - 1]] = dp_last.ccount;
                    ret = max(ret, sum(dp_now.mm));
                }
            }
            dp_last = dp_now;

        }
        return ret;
    }

private:
    int sum(map<int, int> &mm) {
        int s = 0;
        for (auto &m : mm) {
            s += m.second;
        }
        return s;
    }

    struct dp_item {
        int ccount;
        map<int, int> mm;

        dp_item() {
        }


        dp_item(int count) : ccount(count) {
        }
    };
};


struct T {
    vector<int> trees;
    int expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 2, 1}},
                    3,
            },

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.totalFruit(t.trees), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


