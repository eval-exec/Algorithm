#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        // 0 1 2 3 4 5      size-k-1,size-k,size-k+1, ..., size-2 ,size-1
        memo = vector<int>(nums.size());

        {
            if (nums.size() > k) {
                memo[nums.size() - k - 1] = nums.size() - k - 1;
                int minL = nums[nums.size() - k - 1];
                for (int i = nums.size() - k - 2; i >= 0; i--) {
                    if (nums[i] <= minL) {
                        minL = nums[i];
                        memo[i] = i;
                    } else {
                        memo[i] = memo[i + 1];
                    }
                }
            }
        }

        {

            memo[nums.size() - k] = nums.size() - k;
            int minR = nums[nums.size() - k];
            for (int i = nums.size() - k + 1; i < nums.size(); i++) {
                if (nums[i] < minR) {
                    minR = nums[i];
                    memo[i] = i;
                } else {
                    memo[i] = memo[i - 1];
                }
            }
        }

        vector<int> ret(k);
        int left = 0, right = nums.size() - k;
        for (int i = 0; i < k; i++, right++) {
            int idx = pick(nums, left, right, k);
            ret[i] = nums[idx];

            left = idx + 1;
        }
        return ret;
    }

private:
    vector<int> memo;

    int min_id(const vector<int> &nums, const int &left, const int &right) {
        int id = left;
        int min_n = nums[left];
        for (int i = left; i <= right; i++) {
            if (nums[i] < min_n) {
                min_n = nums[i];
                id = i;
            }
        }
        return id;

    }


    int pick(const vector<int> &nums, const int &left, const int &right, const int &k) {
        int mid = nums.size() - k;
        if (left <= mid - 1 && right >= mid) {
            int id_l = memo[left];
            int id_r = memo[right];
            return nums[id_l] <= nums[id_r] ? id_l : id_r;
        }
        return min_id(nums, left, right);
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


