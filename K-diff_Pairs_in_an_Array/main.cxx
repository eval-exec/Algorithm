#include <gtest/gtest.h>

using namespace std;

//void debug(string c) {
//    cout << c << endl;
//}

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int count = 0;
        map<int, int> cont;
        for (auto &v:nums) {
            if (cont.find(v) != cont.end()) {
                cont.find(v)->second += 1;
            }
            cont.insert(pair<int, bool>(v, 1));
        }


        for (auto &key_val : cont) {
            if (cont.find(key_val.first + k) != cont.end()) {
                if (k == 0) {
                    if (cont.find(key_val.first)->second > 1) {
                        count++;
                    }
                } else {
                    count++;
                }
            }
        }
        return count;

    }
};


struct TestCase {
    vector<int> nums;
    int k;
    int expect;
};
TEST(Solution, findPairs) {
    Solution solution;

    TestCase testCases[] = {
            {.nums = {3, 1, 4, 1, 5}, .k = 2, .expect = 2},
            {.nums = {1, 2, 3, 4, 5}, .k = 1, .expect = 4},
            {.nums = {1, 3, 1, 5, 4}, .k = 0, .expect = 1},
            {.nums = {1, 2, 4, 4, 3, 3, 0, 9, 2, 3}, .k = 3, .expect = 2},
            {.nums = {-1, -2, -3}, .k = 1, .expect = 2},

    };


    for (auto t : testCases) {
        GTEST_ASSERT_EQ(t.expect, solution.findPairs(t.nums, t.k));
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}