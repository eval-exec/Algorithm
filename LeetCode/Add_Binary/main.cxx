
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        map<char, int> mm = {
                {'0', 0},
                {'1', 1},
        };
        int lena = a.size();
        int lenb = b.size();
        if (lena < lenb) {
            string tmp = a;
            a = b;
            b = tmp;
            int t = lena;
            lena = lenb;
            lenb = t;
        }
        int count = 0;
        for (int i = 0; i < lena; i++) {
            int ia = 0;
            int ib = 0;
            ia = mm[a[lena - 1 - i]];
            if (i < lenb) {
                ib = mm[b[lenb - 1 - i]];
            }
            int s = ia + ib + count;
            if (s >= 2) {
                s = s - 2;
                count = 1;
            } else {
                count = 0;
            }
            a[lena - 1 - i] = '0' + s;
        }
        if (count != 0) {
            a.insert(a.begin(), '0' + 1);
        }
        return a;
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


