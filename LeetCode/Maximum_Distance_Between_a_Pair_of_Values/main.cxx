#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Distance Between a Pair of Values

*/

class Solution {
  public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        map<int, set<int>> mm;
        for (int i = 0; i < nums1.size(); i++) {
            mm[nums1[i]].insert(i);
        }
        int maxd = 0;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            const auto l = mm.lower_bound(nums2[i]);
            int n1i = 0;
            if (l == mm.end()){
                auto p = prev(l);
                n1i = *p->second.begin();
                maxd = max(maxd, i - n1i);
            }else if (l->first == nums2[i]) {
                n1i = *l->second.begin();
                maxd = max(maxd, i - n1i);
            }else if (l != mm.begin()){
                auto p = prev(l);
                n1i = *p->second.begin();
                maxd = max(maxd, i - n1i);
            }
            if (i < nums1.size()) {
                mm[nums1[i]].erase(i);
                if (mm[nums1[i]].empty()) {
                    mm.erase(nums1[i]);
                }
            }
        }
        return maxd;
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


