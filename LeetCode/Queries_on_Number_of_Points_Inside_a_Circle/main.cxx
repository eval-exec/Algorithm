#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START ## Queries on Number of Points Inside a Circle

class Solution {
  public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> rets;
        for (const auto &query:queries) {
            int count = 0;
            for (const auto &point:points) {
                if (inside(point, query))count++;
            }
            rets.push_back(count);
        }
        return rets;
    }
  private:
    bool inside(const vector<int> &point, const vector<int> query) {
        return pow(point[0] - query[0], 2) + pow(point[1] - query[1], 2) <= pow(query[2], 2);
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


