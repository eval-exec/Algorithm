#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*

Given the coordinates of four points in 2D space,
 return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
 */

void print(vector<int> n) {
    printf("%d %d\n", n[0], n[1]);
}

class Solution {
private:
    int dist(const vector<int> &n1, const vector<int> &n2) {
        int ret = pow(n1[0] - n2[0], 2) + pow(n1[1] - n2[1], 2);
        return ret;
    }

    // exception throw
    bool dist2(const vector<int> &n, const vector<vector<int>> &ns, vector<int> &ret) {
        ret = ns[0];
        map<int, set<int> > mm;
        for (int i = 0; i < 3; i++) {
            int d = dist(n, ns[i]);
            mm[d].insert(i);
        }
        if (mm.size() == 3) {
            return false;
        }
        for (auto &m : mm) {
            if (m.second.size() == 1) {
                ret = ns[*m.second.begin()];
                return true;
            }
        }

        return false;
    }

    bool equal(vector<int> n1, vector<int> n2) {
        return n1[0] == n2[0] && n1[1] == n2[1];
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        vector<vector<int>> ns = {p1, p2, p3, p4};
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (equal(ns[i], ns[j])) return false;
            }
        } // all nodes are different


        vector<int> n1 = p1;
        vector<int> n2;
        bool ok = dist2(n1, {p2, p3, p4}, n2);
        if (!ok) {
            return false;
        }

        vector<vector<int>> another;
        vector<vector<int>> neq = {p2, p3, p4};
        for (auto &n : neq) {
            if (dist(n2, n1) != dist(n1, n)) {
                another.push_back(n);
            }
        }

        vector<int> m1 = another[0];
        vector<int> m2 = another[1];

        if (dist(n1, n2) != dist(m1, m2)) {
            return false;
        }


        if (dist(n1, m1) != dist(n1, m2)) {
            return false;
        }
        if (dist(n2, m1) != dist(n2, m2)) {
            return false;
        }
        if (dist(m1, n1) != dist(m1, n2)) {
            return false;
        }
        if (dist(m2, n1) != dist(m2, n2)) {
            return false;
        }

        return true;


    }
};


struct T {
    vector<int> p1, p2, p3, p4;
    bool expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    .p1={0, 0},
                    .p2={1, 1},
                    .p3={0, 1},
                    .p4={1, 0},
                    .expect=true
            },
            {
                    {{1, 1}},
                    {{0, 1}},
                    {{1, 2}},
                    {{0, 0}},
                    false
            }

    };


    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.validSquare(t.p1, t.p2, t.p3, t.p4), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


