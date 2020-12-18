#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    bool validUtf8(vector<int> &data) {
        if (data.empty()) return true;
        for (int d : data) {
            if (d > 255) {
                return false;
            }
        }
        if ((data[0] & (~(1 << 7))) == data[0]) {
            vector<int> tmp(data);
            tmp.erase(tmp.begin());
            return validUtf8(tmp);
        }
        if (data.size() <= 1) return false;
        int mask = 1 << 7;
        int len = 2;
        int head = data[0];
        for (len = 2; len <= 4; len++) {
            mask += (1 << (8 - len));
            if ((mask | head) != head) continue;
            if ((head & (~(1 << (8 - len - 1)))) != head) continue;
            break;
        }
        if (len == 5) return false;
        if (len > data.size()) return false;
        for (int i = 1; i < len; i++) {
            int now = data[i];
            if ((now | 1 << 7) != now || (now & (~(1 << 6))) != now)
                return false;
        }
        vector<int> tmp(data.begin() + len, data.end());
        return validUtf8(tmp);
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


