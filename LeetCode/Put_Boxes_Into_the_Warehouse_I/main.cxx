#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Put Boxes Into the Warehouse I

*/

class Solution {
  public:
    int maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse) {
        sort(boxes.begin(), boxes.end());
        vector<int> wmin(warehouse.size());
        {
            int wm = INT_MAX;
            for (int i = 0; i < warehouse.size(); i++) {
                wm = min(wm, warehouse[i]);
                wmin[i] = wm;
            }
        }
        int bi = 0;
        for (int i = wmin.size() - 1; i >= 0; i--) {
            if (bi == boxes.size()) return boxes.size();
            if (boxes[bi] <= wmin[i]) {
                bi++;
            }
        }
        return bi;
    }
};

//// END
struct T {

};

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


