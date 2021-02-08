
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int i = l; // cursor for final pivot location
        for (int j = l; j <= r - 1; j++) { // nums[r] is chosen as the pivot
            if (nums[j] <= nums[r]) {
                swap(nums[i], nums[j]);
                i++; // smaller or equal elements go to the left of i
            }
        }
        swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
};

class Solution2 {


    vector<int> sort(vector<int> &nums, int index, int len) {
        if (len == 0) {
            return {};
        }
        if (len == 1) {
            vector<int> x = {nums[index]};
            return x;
        }
        if (len == 2) {
            vector<int> x(2);
            if (nums[index] < nums[index + 1]) {
                x[0] = nums[index];
                x[1] = nums[index + 1];
            } else {
                x[0] = nums[index + 1];
                x[1] = nums[index];
            }
            return x;
        }
        vector<int> l = sort(nums, index, len / 2);
        vector<int> r = sort(nums, index + len / 2, len - len / 2);
        return merge(l, r);
    }

    vector<int> merge(const vector<int> l, const vector<int> r) {
        vector<int> ret;
        int i1 = 0;
        int i2 = 0;
        while (true) {
            if (l[i1] <= r[i2]) {
                ret.push_back(l[i1]);
                i1++;
            } else {
                ret.push_back(r[i2]);
                i2++;
            }
            if (i1 == l.size() || i2 == r.size()) {
                break;
            }
        }
        if (i1 != l.size()) {
            ret.insert(ret.end(), l.begin() + i1, l.end());
        }
        if (i2 != r.size()) {
            ret.insert(ret.end(), r.begin() + i2, l.end());
        }
        return ret;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


