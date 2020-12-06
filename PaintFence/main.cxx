#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution_TLE {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k));
        int count = 0;
        for (int k1 = 0; k1 < k; k1++) {
            for (int k2 = 0; k2 < k; k2++) {
                count += cal(k1, k2, 2, n, k);
            }
        }
        return count;
    }

private:
    int cal(int p1, int p2, int np, int N, int K) {
        int count = 0;
        if (np == N) {
            for (int k = 0; k < K; k++) {
                if (p2 == k) {
                    if (p1 != k) count++;
                } else {
                    count++;
                }
            }
            return count;
        }
        for (int k = 0; k < K; k++) {
            if (p1 == k) continue;
            else count += cal(p2, k, np + 1, N, K);
        }
        return count;
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 0) return 0;
        memo[0] = k;
        memo[1] = k * k;
        return cal(n, k);
    }

private:
    unordered_map<int, int> memo;

    int cal(int n, int k) {
        auto f = memo.find(n);
        if (f != memo.end()) return f->second;
        int result = (k - 1) * (cal(n - 1, k) + cal(n - 2, k));
        memo[n] = result;
        return result;
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


