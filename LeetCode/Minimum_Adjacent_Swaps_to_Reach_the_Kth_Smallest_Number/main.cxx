#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimum Adjacent Swaps to Reach the Kth Smallest Number

*/
class Solution {
  public:
    int getMinSwaps(string num, int k) {
        vector<int> nums;
        for (auto n : num) {
            nums.push_back(n - '0');
        }
        vector<int> tmp(nums);
        for (int ki = 0; ki < k; ki++) {
            perm(tmp);
        }
        int count = 0;
        int start = 0;
        while (nums != tmp) {
            for (int i = start; i + 1 < nums.size(); i++) {
                if (nums[i] == tmp[i]) {
                    start = i + 1;
                    continue;
                }
                int xi = i + 1;
                while (nums[xi] != tmp[i]) {
                    xi++;
                }
                nums.erase(nums.begin()+xi);
                nums.insert(nums.begin()+i,tmp[i]);
                count += xi-i;
                break;
            }
        }
        return count;
    }
    void perm(vector<int> &nums) {
        int mxi = nums.size() - 1;
        int mx = nums[mxi];
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxi = i;
            }
            if (nums[i] < mx) {
                for (int x = i + 1; x < nums.size(); x++) {
                    if (nums[x] > nums[i]) {
                        if (nums[x] < mx) {
                            mx = nums[x];
                            mxi = x;
                        }
                    }
                }
                swap(nums[i], nums[mxi]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
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


