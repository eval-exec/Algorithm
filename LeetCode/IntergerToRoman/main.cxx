#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
        string ret;
        int n = 0;
        while (num > 0) {
            int r = num % 10;
            int b = pow(10, n);
            int v = r * b;
            string now;
            if (r == 9) {
                now.push_back(mm[b]);
                now.push_back(mm[10 * b]);
            } else if (r == 4) {
                now.push_back(mm[b]);
                now.push_back(mm[5 * b]);
            } else {
                while (r > 0) {

                    if (r >= 5) {
                        now.push_back(mm[5 * b]);
                        r -= 5;
                    } else {
                        now.push_back(mm[b]);
                        r--;
                    }
                }
            }
            ret = now + ret;

            num /= 10;
            n++;
        }
        return ret;
    }

  private:
    unordered_map<int, char> mm = {
        {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'},
        {100, 'C'}, {500, 'D'}, {1000, 'M'},
    };
};

struct T {};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
