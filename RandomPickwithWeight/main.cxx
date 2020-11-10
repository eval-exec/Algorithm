#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
private:
    map<int, int> mm;
    int sum;

public:
    Solution(vector<int> &w) {
        mm[w[0]] = 0;
        for (int i = 1; i < w.size(); i++) {
            w[i] += w[i - 1];
            mm[w[i]] = i;
        }
        sum = w[w.size() - 1];
    };


    int pickIndex() {
        long r = random();
        int rr = r;
        int s = rr % sum + 1;
        return mm.lower_bound(s)->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */




struct T {
    vector<int> w;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
            },
            {
                    {{1,3}}
            },
            {
                    {{4,8,12}}
            }

    };


    for (T t : ts) {
        Solution solution(t.w);
        int n = 1000000;
        map<int, int> mm;
        while (n > 0) {
            int p = solution.pickIndex();
            mm[p] += 1;
            n--;
        }

        int first = -1;
        for (auto m : mm) {
            if (first == -1) {
                first = m.second;
            }
            printf("%d %d %f \n", m.first, m.second, m.second / float(first));
        }

        cout << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


