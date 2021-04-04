#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        long allsum = 0;
        int len = nums1.size();
        set<int> st;
        for (int i = 0; i < len; i++) {
            st.insert(nums1[i]);
            allsum += abs(nums1[i] - nums2[i]);
        }
        long ret = allsum;
        for (int i = 0; i < len; i++) {
            if (nums1[i] == nums2[i]) continue;
            long v1 = abs(nums1[i] - nums2[i]);

            auto l = st.lower_bound(nums2[i]);
            int v2 = 0;
            if (l == st.end()) {
                v2 = abs(*st.rbegin() - nums2[i]);
            } else {
                v2 = abs(*l - nums2[i]);
                if (l != st.begin()) {
                    v2 = min(v2, abs(*prev(l) - nums2[i]));
                }
            }
            if (v2 < v1) {
                ret = min(ret, allsum - (v1 - v2));
            }
        }
        return ret %long(1e9+7);
    }
};

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


