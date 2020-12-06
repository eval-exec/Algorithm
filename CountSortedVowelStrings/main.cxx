#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int countVowelStrings(int n) {
        return count(5, n);
    }

private:
    map<pair<int, int>, int> mm;

    int count(int v, int n) {
        if (v == 1) return 1;
        if (n == 1) return v;
        auto f = mm.find({v, n});
        if (f != mm.end()) return f->second;
        int ret = 0;
        for (int i = 0; i < v; i++) {
            ret += count(v - i, n - 1);
        }
        mm[{v, n}] = ret;
        return ret;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };


    for (T t : ts) {
        Solution solution;
        int n;
        while (true) {

            cin >> n;
            cout << solution.countVowelStrings(n) << endl;
        }
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


