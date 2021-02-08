#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class P {
  public:
    int index;
    int step;
    bool operator<(const P &p) const {
        return step > p.step;
    }
};
class Solution {
  public:
    int findRotateSteps(string ring, string key) {
        ring_len = ring.size();
        for (int i = 0; i < ring.size(); i++) {
            mm[ring[i]].insert(i);
        }
        return find(key, 0, 0);
    }
  private:
    unordered_map<int, int> memo;
    int find(string key, int ki, int ri) {
        if (ki == key.size()) return 0;
        {
            auto f = memo.find(ki * 1000 + ri);
            if (f != memo.end()) return f->second;
        }

        int count = INT_MAX;
        vector<P> ps = index(key[ki], ri);
        for (P p : ps) {
            count = min(count, p.step + 1 + find(key, ki + 1, p.index));
        }

        memo[1000 * ki + ri] = count;
        return count;
    }

    unordered_map<char, unordered_set<int>> mm;
    int ring_len = 0;
    vector<P> index(const char &c, int ni) {
        int ci = ni;
        vector<P> rets;
        for (const int &s: mm[c]) { // 1 2 3 4 5
            int dis = min(abs(ci - s), ring_len - abs(ci - s));
            rets.push_back({s, dis});
        }
        return rets;
    }
};

struct T {
    string ring;
    string key;
    int expect;
};

TEST(Solution, test) {
    T ts[] = {
        {
            "goooddding",
            "gdg",
            13

        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.findRotateSteps(t.ring, t.key), t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


