#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


void print() {
    for (int n : sot) {
        cout << n << " ";
    }
    cout << endl;
}

class Solution {
private:
    vector<int> sot;

    
    int first(int n) {
        int left = 0, right = sot.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sot[mid] >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        int len = nums.size();
        vector<int> ret(len);
        for (int i = len - 1; i >= 0; i--) { // 0 1 1 1 1 3
            int index = first(nums[i]);
            sot.insert(sot.begin() + index, nums[i]);
            ret[i] = index;
        }
        return ret;
    }
};


class Solution2 {
private:
    map<int, int> mm;
    map<int, int> memoSum;

    int sumLower(int n) {
        int sum = 0;
        for (auto m : mm) {
            if (m.first < n) {
                sum += m.second;
            }
        }
        return sum;
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> ret(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            mm[nums[i]] += 1;
            ret[i] = sumLower(nums[i]);
        }

        return ret;

    }
};


struct T {
    vector<int> nums;
    vector<int> expect;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{5, 2, 6, 1}},
                    {{2, 1, 1, 0}},

            },

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.countSmaller(t.nums), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


