#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        auto f = mm.find(N);
        if (f != mm.end()) return f->second;
        int x = 1;
        while (x < N) {
            if (N % x == 0) {
                if (!divisorGame(N - x)) {
                    mm[N] = true;
                    return true;
                }
            }
            x++;
        }
        mm[N] = false;
        return false;
    }

private:
    map<int, bool> mm;
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
        cout << solution.divisorGame(5) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


