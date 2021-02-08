/*
 *
 *Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.

Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.



Example 1:

Input: heights = [1,1,4,2,1,3]

Output: 3

Explanation:

Current array : [1,1,4,2,1,3]

Target array  : [1,1,1,2,3,4]

On index 2 (0-based) we have 4 vs 1 so we have to move this student.

On index 4 (0-based) we have 1 vs 3 so we have to move this student.

On index 5 (0-based) we have 3 vs 4 so we have to move this student.

Example 2:

Input: heights = [5,1,2,3,4]

Output: 5

Example 3:

Input: heights = [1,2,3,4,5]

Output: 0


Constraints:

1 <= heights.length <= 100
1 <= heights[i] <= 100

 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        vector<int> nums = heights;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int count = 0;
        for (int i = 0; i <= len - 1; i++) {
            if (heights[i] != nums[i]) {
                count++;
            }
        }
        return count;
    }
};

void print(vector<int> vs) {
    for (int v : vs) {
        cout << v << " ";
    }
    cout << endl;
}


TEST(Solution, heightsChecker) {
    Solution solution;

    vector<int> heights;
    int count;
    heights = {1, 1, 4, 2, 1, 3};
    count = solution.heightChecker(heights);
    EXPECT_EQ(count, 3);


    heights = {5, 4, 3, 2, 1};
    count = solution.heightChecker(heights);
    EXPECT_EQ(count, 4);

    heights = {5,1,2,3,4};
    count = solution.heightChecker(heights);
    EXPECT_EQ(count, 5);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


