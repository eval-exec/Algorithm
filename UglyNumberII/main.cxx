#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*
   2 3 5
   4 6 10, 6 9 15 10 15 25
   


*/


class Solution {
  public:
    int nthUglyNumber(int N) {
        if (N <= 0) return 0;
        priority_queue<int, vector<int>, std::greater<> > min_heap;
        unordered_set<int> added;
        min_heap.push(1);
        int n = 1;
        while (n < N) {
            int m = min_heap.top();
            min_heap.pop();
            if (added.count(m * 2) == 0) {
                min_heap.push(m * 2);
                added.insert(m * 2);
            }
            if (added.count(m * 3) == 0) {
                min_heap.push(m * 3);
                added.insert(m * 3);
            }
            if (added.count(m * 5) == 0) {
                min_heap.push(m * 5);
                added.insert(m * 5);
            }
            n++;
        }
        return min_heap.top();
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


