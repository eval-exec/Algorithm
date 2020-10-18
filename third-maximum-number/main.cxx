#include <bits/stdc++.h>
#include <gtest/gtest.h>

/*
 *
 * Given a non-empty array of integers,
 * return the third maximum number in this array.
 * If it does not exist,
 * return the maximum number.
 * The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
 */

using namespace std;

void print(vector<int> nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        vector<int> maxs;

        for (int n : nums) {
            add(maxs, n);
        }

        return getRank(maxs);
    }

private:
    int getRank(vector<int> &maxs) {
        if (maxs.size() == 0) {
            return 0;
        }

        sort(maxs.begin(), maxs.end());
        if (maxs.size() != 3) {
            return maxs[maxs.size() - 1];
        }
        return maxs.at(0);
    }

    void add(vector<int> &maxs, int n) {


        int len = maxs.size();

        sort(maxs.begin(), maxs.end());

        for (int i = len - 1; i >= 0; i--) {
            if (maxs[i] == n) {
                return;
            }
            if (maxs.size() == 3) {
                if (maxs[i] < n) {
                    maxs[0] = n;
                    return;
                }
            }
        }
        if (maxs.size() != 3) {
            maxs.push_back(n);
        }


    }
};


TEST(Solution, thirdMax) {
    Solution solution;
    vector<int> nums;
    int num;


    nums = {2, 2, 3, 1};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {3, 2, 1};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {1, 2};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {5, 2, 2};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {1, 2, 2, 5, 3, 5};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {5, 2, 4, 1, 3, 6, 0};
    print(nums);
    cout << solution.thirdMax(nums) << endl;


    nums = {1, 2, 2, 5, 3, 5};
    print(nums);
    cout << solution.thirdMax(nums) << endl;
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


