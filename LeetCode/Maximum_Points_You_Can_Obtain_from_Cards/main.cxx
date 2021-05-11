#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Points You Can Obtain from Cards

*/


class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {

        int wind = cardPoints.size() - k;
        int sum = 0;
        for (int i = 0; i < wind; i++) {
            sum += cardPoints[i];
        }
        int totalSum = 0;
        for (int i = 0; i < cardPoints.size(); i++) {
            totalSum += cardPoints[i];
        }

        int minwindSum = sum;

        for (int i = wind; i < cardPoints.size(); i++) {
            sum += cardPoints[i];
            sum -= cardPoints[i - wind];
            minwindSum = min(minwindSum,sum);
        }
        return totalSum - minwindSum;
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


