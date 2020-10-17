
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0) {
            return;
        }

        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int len1 = nums1.size();
        // * * * o o
        // * *
        // 2,0
        // 1,
        int i1 = len1 - 1;
        int i2 = n - 1;
        for (int i = m - 1; i >= 0 && i2 >= 0;) {
            if (nums1.at(i) > nums2.at(i2)) {
                nums1.at(i1) = nums1.at(i);
                i--;
            } else {
                nums1.at(i1) = nums2.at(i2);
                i2--;
            }
            i1--;
        }
        for (int i = i2; i >= 0; i--) {
            nums1.at(i) = nums2.at(i);
        }
    }
};

void print(vector<int> vs) {
    for (int v : vs) {
        cout << v << " ";
    }
    cout << endl;
}

struct T {
    vector<int> nums1;
    int m;
    vector<int> nums2;
    int n;
    vector<int> expect;

    T(vector<int> n1, int a1, vector<int> n2, int a2, vector<int> n3) {
        nums1 = n1;
        m = a1;
        nums2 = n2;
        n = a2;
        expect = n3;
    }
};

TEST(Solution, merge) {
    T ts[] = {
            {
                    {1, 2, 3, 0, 0, 0},
                    3,
                    {2, 5, 6},
                    3,
                    {1, 2, 2, 3, 5, 6},
            },
            {
                    {2, 0},
                    1,
                    {1},
                    1,
                    {1, 2}
            },
            {
                    {4, 5, 6, 0, 0, 0},
                    3,
                    {1, 2, 3},
                    3,
                    {1, 2, 3, 4, 5, 6}
            }
    };

    Solution solution;
    for (T t : ts) {
        print(t.nums1);
        solution.merge(t.nums1, t.m, t.nums2, t.n);
        print(t.nums1);

    }


}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


