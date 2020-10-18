/*
 * Given an array arr,
 *
 * replace every element in that array with the greatest element among the elements to its right,
 *
 * and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
 */
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int len = arr.size();
        int max = arr[len - 1];
        arr[len - 1] = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (arr[i] <= max) {
                arr[i] = max;
            } else {
                int last = max;
                max = arr[i];
                arr[i] = last;
            }
        }
        return arr;
    }
};

void print(vector<int> vs) {
    for (int v:vs) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, replaceElements) {
    Solution solution;

    vector<int> nums;
    nums = {17, 18, 5, 4, 6, 1};
    print(nums);
    solution.replaceElements(nums);
    print(nums);


    nums = {1};
    print(nums);
    solution.replaceElements(nums);

    print(nums);


    nums = {1,2};
    print(nums);
    solution.replaceElements(nums);
    print(nums);
}


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


