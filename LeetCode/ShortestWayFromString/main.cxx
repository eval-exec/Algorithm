#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int shortestWay(string source, string target) {
        map<char, set<int>> mm;
        for (int i = 0; i < source.size(); i++) {
            mm[source[i]].insert(i);
        }
        int idx = 0;
        int count = 0;
        int start_flag = true;
        for (int i = 0; i < target.size(); i++) {
            auto l = mm[target[i]].lower_bound(idx);
            if (l == mm[target[i]].end()) {
                if (start_flag) return -1;
                count++;
                idx = 0;
                i--;
                start_flag = true;
            } else {
                idx = *l + 1;
                start_flag = false;
            }
        }
        return count+1;
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


