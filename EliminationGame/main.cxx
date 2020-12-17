#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Ret {
  public:
    int left;
    int right;
    int delta;
    Ret(int l, int r, int d) {
        left = l;
        right = r;
        delta = d;
    }
};

/*
// 1 2 3 4 5 6 7 8 9 10
   2 4 6 8 10
   4 8
 *
 */


class Solution {
  public:
    int lastRemaining(int n) {
        Ret r = Ret(1, n, 1);
        bool head = true;
        while (r.left + r.delta <= r.right) {
            rotate(r, head);
            head = !head;
        }
        return r.left;
    }
  private:
    void rotate(Ret &r, const bool &head) {
        if (head) {
            if ((r.right - r.left) % (r.delta * 2) == 0) {
                r.right -= r.delta;
            }
            r.left += r.delta;
        } else {
            if ((r.right - r.left) % (r.delta * 2) == 0) {
                r.left += r.delta;
            }
            r.right -= r.delta;
        }
        r.delta *= 2;
    }
};

struct T {
    int in;
    int out;

};

TEST(Solution, test) {
    T ts[] = {
        {
            9,
            6
        },
        {
            10,
            8
        },
        {
            19,
            8
        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.lastRemaining(t.in), t.out);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


